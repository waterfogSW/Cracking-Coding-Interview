# [RocksDB] 1. Introduction

## What is RocksDB?
![image](https://user-images.githubusercontent.com/28651727/124079851-a09b4280-da84-11eb-87c1-c8e525739628.png)

RocksDB는 Facebook사에서 개발한 LSM(Log Structured Merge)기반의 No SQL데이터 베이스 저장 엔진입니다.

정보 통신 기술의 발전으로 전 세계의 데이터 생산량이 기하 급수적으로 증가하였고, 이에따라 기존의 관계형 데이터베이스(RDBMS)보다 대용량의 데이터를 효율적으로 저장하고 관리할 수 있는 기술이 중요해 졌고 이에따라 NoSQL데이터 베이스가 등장하게 되었습니다. 

NoSQL데이터 베이스는 다음의 몇가지 특징을 가집니다.
- Dynamic Schema
  - RDBMS에서는 데이터베이스에 데이터를 저장하기 전에 사전에 스키마를 정의하여야 합니다. 반면 NoSQL의 경우 사전 정의된(pre-defined) 스키마를 요구하지 않아 데이터 및 요구 사항이 변경됨에 따라 NoSQL 데이터베이스를 훨씬 쉽게 업데이트할 수 있습니다. 
- Data structure
  - RDBMS가 테이블 기반인 반면 NoSQL데이터베이스의 경우 document based, graph databases, key-value pairs, 또는 wide-column stores가 될 수 있습니다. 때문에 더 자유롭게 [`비정형 데이터`](https://www.mongodb.com/unstructured-data)를 처리할 수 있습니다
- Scaling
  - 수직적 확장이 필요한 RDBMS의 경우 더 비싼 단일 서버를 요구하여 확장 비용이 크지만, NoSQL 데이터베이스의 경우 범용의 값싼 서버를 추가하는것으로 수평적 확장이 가능하여 확장비용이 저렴합니다.

NoSQL데이터 베이스에는 대표적으로 Amazon의 DynamoDB, MongoDB, Github의 Redis, Google의 LevelDB 그리고 Facebook의 RocksDB가 있습니다. 그중 RocksDB는 Google에서 개발한 LevelDB를 fork하여 Facebook에서 개발한 오픈소스 프로젝트로 고성능 저장장치에 최적화된 Key-Value 데이터베이스입니다.

### Key-value Store?
Key-Value store에서는 데이터의 각 조각들을 Key-Value쌍으로 구성하여 키를 사용하여 데이터베이스에 값을 저장합니다. 애플리케이션이 데이터를 검색할때 Key를 Key-Value Store에 제공하면, Key-Value Store는 Key를 해시하여 저장소에서 Value를 가져옵니다.

## RocksDB Architecture
![image](https://user-images.githubusercontent.com/28651727/124079742-806b8380-da84-11eb-8aa4-fc306c967f27.png)

RocksDB는 크게 Memtable, sstfile, logfile 3가지로 구성되어 있습니다. 

쓰기요청이 발생하면 메모리의 임시버퍼인 Memtable에 쓰기작업을 진행합니다. Memtable이 꽉 차게되면 읽기 전용의 immutable memtable로 전환(switch)되고 새로운 Memtable을 생성하여 새로 들어오는 쓰기 요청을 진행합니다. 

이후 Immutable memtable이 특정 개수에 도달하면 저장장치로 옮겨 sstfile로 저장하게 되는데 이러한 작업을 `flush`라고 합니다. 

sstfile은 키를 쉽게 찾아보기 위해 모든 key-value 데이터들을 정렬아여 저장하고, 로그 구조의 병합 트리 구조를 가지고 저장 장치 내에서 컴팩션을 통해 업데이트 됩니다.

## Appendix
### Rocks DB vs LevelDB

| LevelDB                                                       | RocksDB                     |
| ------------------------------------------------------------- | --------------------------- |
| Developed by Google                                           | Developed by Facebook       |
| Open Source                                                   | Open Source                 |
| Key-Value Store                                               | Key-Value Store             |
| github.com/­google/­leveldb                                   | rocksdb.org                 |
| Built in C++                                                  | Built in C++                |
| No Transactions                                               | Transactions are supported. |
| Concurrency supported                                         | Concurrency supported.      |
| NodeJs,Python,Java C++,Go Api available to access the LevelDB | C++ and Java Api available. |

### Reference
- RocksDB wiki : https://github.com/facebook/rocksdb/wiki
- NoSQL vs Relational Databases : https://www.mongodb.com/scale/nosql-vs-relational-databases