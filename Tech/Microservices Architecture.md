# Microservices Architecture
<p align= center>
<img src=https://user-images.githubusercontent.com/28651727/123539994-8f49f180-d777-11eb-9895-2c35922c2357.png>
</p>
마이크로 서비스는 대규모 소프트웨어 프로젝트를 마이크로 단위의 모듈로 분리하여 loosely-coupled한 구조로 만든후 API를 통해 통신합니다.

## BackGround
웹 개발시 Presentation layer(사용자 인터페이스)를 디자인하고 Application layer와 구성요소간의 느슨한 결합을 가능하게 하는 Integration layer, 데이터 접근을 위한 Persistence layer를 디자인하고 구현합니다.

SOA(Service Oriented Architecture)와 같은 기존 아키텍처의 경우 어플리케이션을 구동하기 위해 `war or ear`패키지를 생성하고 `Tomcat`, `JBoss`와 같은 Application server에 배포하는데 모든 모듈이 `war or ear`로 패키징 되어있기 때문에 이를 `Monolithic`이라고 부릅니다.

<p align= center>
<img src=https://user-images.githubusercontent.com/28651727/123539818-8a387280-d776-11eb-8666-ec7183ad661b.png>
</p>

이러한 `Monolithic`의 경우 다음과 같은 단점을 가지고 있습니다.
1. 어플리케이션이 커질 수록 코드도 방대해지고 로드시에 IDE에 과부하가 걸릴 수 있습니다. 이런 부분은 개발자의 생산성을 저하시키는 요인이 됩니다.
2. 하나의 war or ear에 모든 것을 포함하였기에 어플리케이션의 기술 스택을 변경하는 것을 주저하게 됩니다. 예를 들어서 일부 컴포넌트는 JVM내에서 동작하는 Groovy나 Scala와 같은 다른 언어를 사용하여 처리하려고 할 경우 이런 종류의 아키텍처를 사용하면 어떤 side-effect가 발생 할지 예측이 어려우므로 리펙토링을 해야 하지만 코드가 너무 방대해서 리펙토링을 하기가 어렵습니다.
3. 어플리케이션내의 특정 기능이 실패하면 전체 어플리케이션에 영향을 미칩니다. 그리고 퍼포먼스가 나쁜 특정 함수/메소드의 영향이 전체 어플리케이션에 고통을 주게 됩니다.
4. 이런 아키텍처에서의 scaling은 서버마다 동일한 war or ear을 배포하여 수행해야 합니다. 각각 서버는 동일한 리소스를 사용하게 되므로 이 것은 효율적인 방법이 아닙니다.
5. 어플리케이션이 커질수록 개발자는 작은 단위로 작업을 축소할 수 있어야 합니다. Monolithic은 모든 것이 하나로 묶여 있기 때문에 개발자가 독립적으로 모듈을 개발하고 배포 할 수 없습니다. 그리고 개발은 협업으로 진행되므로 다른 개발자에 의존성때문에 개발 시간이 길어지게 됩니다.

## Microservice Architecture
마이크로 서비스 아키텍처의 포인트는 바로 확장성입니다. 많은 사람들이 확장성을 이야기 할 때는 `The Art of Scalability`라는 책을 인용합니다. 이 책에서는 Scaling을 세 가지로 정의합니다.

<p align= center>
<img src=https://user-images.githubusercontent.com/28651727/123539863-c075f200-d776-11eb-9b97-c957cb048d8d.png>
</p>
X 축은 horizontal(수평) application scaling (Monolithic 아키텍처에서도 가능)을 나타내며, Z축은 비슷한 것들을 분할하여 어플리케이션을 스케일링함을 의미합니다. (Z축은 데이터를 분할하여 사용자의 요청에 따라 해당 샤드에 redirect하는 샤딩 개념으로 이해하면 됩니다.)

Y축이 가장 중요하고 우리가 눈여겨 봐야할 대상입니다. 이 축은 기능적인 분해(해체)를 의미합니다. Monolithic에 포함되어 있는 다양한 기능을 독립적인 서비스로 바라보는 전략을 취합니다. 따라서 모든 기능을 전체 어플리케이션에 배포하지 않고 각각 서비스를 독립적으로 배포 할 수 있습니다.

이렇게 하면 개발자의 생산성이 향상되고 기능 변경시 side-effect 걱정 없이 변경하고 배포 할 수 있는 유연성을 제공합니다.

예전 Monolithic 방식과 비교해보세요.
<p align= center>
<img src=https://user-images.githubusercontent.com/28651727/123539865-c2d84c00-d776-11eb-97b8-66e4d7c10c39.png>
</p>
## Advantage of Microservice Architecture
벤더사 중심의 SOA에 비해서 마이크로서비스는 Amazon, Netflix, eBay와 같은 글로벌 서비스 플레이어가 사용할 만큼 강력합니다.
- Improves fault isolation : 단일 모듈의 장애에 대해 전체 어플리케이션은 크게 영향을 받지 않습니다.
- Eliminates long-term commitment to a single technology stack : 각 개별 서비스에서 새로운 기술 스택을 시험하고자 한다면 바로 시작할 수 있습니다. 의존 관계가 기존 Monolithic 아키텍처보다 적고 유연합니다.
- 기능 단위로 서비스가 되기에 새로 조인한 개발자가 기능을 더 쉽게 이해 할 수 있습니다.

## 마이크로 서비스의 배포 및 가상화
마이크로 서비스기반의 어플리케이션을 배포하는 가장 좋은 방법은 컨테이너 가상화를 이용하는 것입니다. (Docker)

AWS와 같은 IaaS업체의 VM을 이용하여 마이크로 서비스를 배포할 수 있지만 작은 단위의 마이크로 서비스는 VM의 리소스를 전부 활용 하지 못해 비용 효율성을 저하 시킬 수 있습니다. 따라서 컨테이너 기반으로 배포를 하는 것이 유리합니다.

OSGI(Open Service Gateway Initiative) 번들을 사용하여 코드를 배포 할 수도 있지만, 이 경우에는 management and isolation tradeoff와 관련된 단점이 존재합니다.
## Disadvantage of Microservice Architecture
아래는 마이크로 서비스 설계와 관련된 잠재적인 약점에 대한 부분입니다.
- 분산 시스템 개발은 일반 개발보다 복잡합니다. 모든 것이 독립적인 서비스이기 때문에 각 모듈간의 인터페이스를 신중하게 처리 해야 합니다. 서비스중 하나가 응답하지 않게 될 경우에 대한 방어코드도 작성해야 합니다. 호출 대기 시간이 발생하게 되면 복잡한 상황이 발생할 수 있습니다.
- Multiple Databases 및 트랜젝션 관리가 어려울 수 있습니다.
- 마이크로 서비스 기반의 어플리케이션을 테스트하는 것은 번거로울 수 있습니다. 테스트를 시작하기 전에 의존성이 있는 서비스를 미리 확인해야 합니다.
- 마이크로 서비스의 배포는 복잡 할 수 있습니다. 각 서비스 간의 조정이 필요 할 수 있습니다.

하지만, 이런 부분들은 자동화 도구를 사용하면 해결 할 수 있습니다.
끝으로, 마이크로 서비스는 벤더사 중심이 아닌 서비스사 중심의 아키텍처이고 이미 글로벌 플레이어에 의해 검증이 되어 있습니다.

[출처: https://giljae.medium.com/%EB%A7%88%EC%9D%B4%ED%81%AC%EB%A1%9C%EC%84%9C%EB%B9%84%EC%8A%A4-%EC%95%84%ED%82%A4%ED%85%8D%EC%B2%98-microservices-architecture-%EC%9D%98-%EC%9E%A5%EC%A0%90%EA%B3%BC-%EB%8B%A8%EC%A0%90-7c45615cfe1a]
