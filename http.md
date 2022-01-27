## 인터넷 네트워크

### IP프로토콜

- 지정 IP주소에 데이터 전달
- 패킷이라는 통신 단위로 데이터 전달
- 출발지 IP, 목적지 IP, ...

### TCP
- 3-way hand shake
- TCP Segment : 출발지 PORT, 목적지 PORT, 전송 제어, 순서, 검증정보
- 데이터 전달 보증
- 순서 보장

### UDP
- 3-way handshake X
- 데이터 전달 보증 X
- 순서 보장 X
- IP와 거의 같다 + PORT + Checksum

3-way handshake과정이 없기 때문에 단순하고 빠르다.

최근에 UDP가 각광을 받고 있는데, HTTP3의 최적화를 위해 UDP프로토콜을 사용하기 시작했음.

### Port

- 한번에 둘 이상의 서버와 통신해야 한다면, 포트를 통해 패킷을 구분할 수 있다.
- TCP/IP 패킷에 출발지 PORT와, 목적지 PORT가 들어있음.
- 0~65535까지 할당
  - 0 ~ 1023: 잘 알려진 포트 , 사용하지 않는 것이 좋다.
  - HTTP 80
  - HTTPS 443

### DNS(Domain Name System)

- IP는 기억하기 어렵고 변경될 수 있다.
- DNS서버 : 도메인 -> IP 주소 변환

## URI와 웹브라우저 요청 흐름

### URI(Uniform Resource Identifier)

- URI(Resource Identifier)
  - URL(Resource Locator) : 리소스가 있는 위치를 지정
    - foo://example.com:8042/over/there?name=ferret#nose
  - URN(Resource Name) : 리소스에 이름을 부여
    - urn:example:animal:ferret:nose
    - URN 이름만으로 실제 리소스를 찾을 수 있는 방법이 보편화 되지 않음

### URL 문법

- scheme://[userinfo@]host[:port][/path][?query][#fragment]
- https://www.google.com/search?q=hello&hl=ko

#### Scheme
- 주로 프로토콜 사용
- 프로토콜 : 어떤 방식으로 자원에 접근할 것인가의 규칙
- http는 80, https는 443포트를 주로 사용
- https = http + secure

#### userinfo

- url에 사용자 정보를 포함해서 인증
- 거의 사용하지 않음

#### port

- 접속 포트
- 일반적으로 생략
- 생략시 http(80), https(443)

#### path

- 리소스 경로, 계층적 구조
- /home/file1.jpg
- /members
- /members/100

#### query
- key=value형태
- ?로 시작, &로 추가 가능 ?keyA=valueA&keyB=valueB
- query parameter, query string등으로 불린다.

#### fragment

- html 내부 북마크를 위해 사용

### 웹브라우저 요청 흐름

#### HTTP 요청 메시지

> search?q=hello&hl=ko HTTP/1.1  
> Host: www.google.com

1. 웹브라우저가 HTTP 메시지 생성
2. SOCKET 라이브러리를 통해 전달
3. TCP/IP 패킷 생성, HTTP 메시지 포함

#### HTTP 응답 메시지

> HTTP/1.1 200 OK  
> Content-Type:text/html;charset=utf-8
> Content-Length: 3423  
> \<html>  
>   \<body> ... \</body>  
> \</html>

## HTTP

- TCP : HTTP/1.1, HTTP/2
- UDP : HTTP/3
- 현재는 HTTP/1.1을 주로 사용
  - HTTP/2, /3도 점점 증가

### 클라이언트 서버 구조

- Request Response구조
- 클라이언트는 서버에 요청
- 서버는 요청에 대해 응답

### Stateless vs Stateful

**Stateful**
- 서버는 클라이언트의 상태를 유지
- 장점 : 클라이언트 추가 데이터 전송이 필요 없다.
- 단점 : 동일한 클라이언트에 대해 항상 같은 서버가 유지되어야 한다. -> 서버 증설이 어렵고, 서버 장애 대응이 어려움

**Stateless**
- 서버는 클라이언트의 상태를 유지하지 않음
- 장점 : Scale out, 응답서버를 쉽게 바꿀 수 있다 -> 무한한 서버 증설 가능
- 단점 : 클라이언트의 추가 데이터 전송
- 실무 한계
  - 모든것을 무상태로 설계할 수는 없다(ex 로그인)
  - 일반적으로 브라우저 쿠키와 서버 세션을 통해 상태 유지
  - 상태유지는 최소한만 사용

### 비연결성

**연결을 유지하는 모델**
- 클라이언트와 서버가 연결을 계속 유지하면, 서버 자원이 소모된다

**연결을 유지하지 않는 모델**
- 서버는 연결을 유지하지 않고 최소한의 자원으로 서버를 유지

**HTTP**
- 연결을 유지하지 않는 모델
- 1시간동안 수천명이 서비스를 사용해도 실제 동시에 처리하는 요청 수십개 이하다
  - 웹 브라우저에서 계속 연속해서 검색 버튼을 누르지는 않는다.
- 하지만 TCP/IP연결을 새로 맺어야 한다. (3-way handshake)
- HTTP지속연결(Persistent connection)을 통해 개선

### HTTP 응답 메시지

| 메시지 구조  | HTTP응답 메시지                                                  |
| ------------ | ---------------------------------------------------------------- |
| start-line   | HTTP/1.1 200 OK                                                  |
| header       | Content-Type:text/html;charset=utf-8  <br />Content-Length: 3423 |
| CRLF         | -공백-                                                           |
| message body | -html 내용-                                                      |

**시작라인**
- HTTP 버전
- 상태 코드
  - 200 : 성공
  - 400 : 클라이언트 요청 오류
  - 500 : 서버 내부 오류
- 사람이 이해할 수 있는 짧은 상태코드 설명

**헤더**
- header-field=field-name":"OWSfiled-valueOWS(OWS:띄어쓰기 허용)
- field-name은 대소문자 구분하지 않는다.

**바디**
- html문서, 이미지, 영상, json등 byte로 표현할 수 있는 모든 내용이 들어갈 수 있다.


## HTTP 메서드

### HTTP API 설계

- API URI 정하기
  - URI에서 가장 중요한것은 리소스 식별이다.
  - 회원 관리 서비스에서 등록하고 수정하고 조회하는 행위는 중요하지 않다.
  - 회원이라는 리소스가 증요
  - /members/{id} (계층구조상 상위를 복수형으로)
  - 리소스 : 명사
    - 회원
  - 행위 : 동사
    - 조회 등록 삭제 변경

### HTTP 메서드

**주로 사용하는 메서드**
- GET : 리소스 조회
- POST : 요청 데이터 처리, 주로 등록에 사용
- PUT : 리소스를 대체, 해당 리소스가 없으면 생성
- PATCH : 리소스 부분 변경
- DELETE : 리소스 삭제

**기타 메서드**
- HEAD : GET과 동일하나 메시지 부분 제외하고 상태줄과 헤더만 반환
- OPTIONS : 대상 리소스에 대한 통신 가능 옵션을 설명(CORS에서 사용)
- ...

**GET**
- 리소스 조회
- 서버에 전달하고 싶은 데이터는 쿼리 파라미터를 통해 전달. (?key=value)
- 메시지 바디를 전송할 수 있으나 권장하지 않음
- GET 요청을 받은 서버는 응답데이터를 보냄

**POST**
- 메시지 바디를 통해 서버로 요청 데이터 전달
- 서버는 메시지 다비를 통해 들어온 요청 데이터를 처리
- 주로 신규 리소스 등록, 프로세스 처리에 사용
- 리로스 URI에 POST요청이 오면 요청 데이터를 어떻게 처리할지 리소스마다 따로 정해야 한다.(정해진 양식이 없음)

1. 새 리소스 생성
2. 요청 데이터 처리
   - 데이터를 생성하거나 변경하는 것을 넘어 프로세스를 처리해야 하는 경우
   - POST의 결과로 새로운 리소스가 생성되지 않을 수 있음
     - POST /orders/{orderId}/start-delivery
     - 컨트롤 URI : 리소스만을 가지고 URI를 다 설계할 수 없는경우 컨트롤 URI로 설계
3. 다른 메서드로 처리하기 애매한 경우
   - 다만 조회 데이터의 경우 GET을 사용하는것이 유리(GET : 캐싱가능)

**PUT**
- 리소스 대체
  - 있으면 대체 -> 기존 리소스를 완전 삭제하고 생성
  - 없으면 생성
- 클라이언트가 리소스를 식별
  - POST : /members
  - PUT : /members/100

**PATCH**
- PUT과 달리 리소스를 부분 변경
- PATCH가 지원되지 않는 서버가 부분적으로 존재 -> POST사용

**DELETE**
- 리소스 삭제

### HTTP 속성

- 안전(Safe)
  - 리소스를 변경하지 않는다.
  - GET, HEAD
  - 안전은 리소스만 고려
- 멱등(Idempotent)
  - f(f(x)) = f(x)
  - 한번 호출하든 두번 호출하는 100번 호출하든 결과가 똑같다.
  - GET, PUT, DELETE
  - POST의 경우 두번 호출하면 같은 결제가 중복해서 발생할 수 있으므로 멱등이 아니다.
  - 응답이 없을경우 같은 요청을 자동으로 다시 반복해도 되는지의 판단 근거
  - 외부 요인으로 중간에 리소스가 변경되는것은 고려하지 않는다.
- 캐시가능(Cacheable)
  - 응답 결과 리소스를 캐시해서 사용해도 되는가?
  - GET, HEAD, POST, PATCH 모두 캐시 가능하나 실무에서는 구현의 어려움때문에 GET, HEAD정도만 캐시로 사용
