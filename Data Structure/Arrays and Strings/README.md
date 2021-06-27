# Arrays and Strings 
## Hash tables
Hash table은 key, value쌍을 통해 효율적인 look up을 제공하는 자료구조입니다.

<p align=center>
<img src = https://user-images.githubusercontent.com/28651727/123536530-b992b380-d765-11eb-9b64-0652e5121121.png><br>
출처 : Cracking Coding interview
<p align=center>

### implementation
1. key에 대한 hash code(int or long)를 계산합니다.  
key는 무한하지만 자료형(int)의 크기는 유한하기에 동일한 키값에 대해 같은 hash code를 가질 수 있습니다.

2. hash code를 배열의 index에 매핑합니다. `hash(key) % array_length`  
두개의 서로다른 hash code는 같은 index에 매핑될 수 있습니다.

3. 여러 key값이 존재하는 index에는 key와 value로 구성된 연결리스트가 존재합니다.  
서로다른 key에 같은 hash code, 서로다른 hash code가 같은 index에 매핑된 경우와 같이 **충돌**이 발생할 수 있기 때문에 반드시 연결리스트를 사용해야 합니다. 

이러한 충돌이 매우 빈번한 경우 최악의경우 시간복잡도는 O(n)이 됩니다(n: 모든 key의 개수).
하지만 충돌을 최소화 하도록 잘 구현한 경우 lookup 시간이 O(1)이 되어 효율적으로 동작할 수 있습니다.

또 hash table을 이진 탐색트리로 구현하여 lookup시간의 복잡도를 O(log N)으로 할 수 도 있습니다. 이러한 방법은 배열의 할당크기를 줄여 잠재적으로 더 적은 공간을 사용할 수 있습니다.
