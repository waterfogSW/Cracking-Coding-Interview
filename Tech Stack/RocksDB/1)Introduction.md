# [RocksDB] 1. Introduction

## What is RocksDB?
<div align=center>
<img src=https://user-images.githubusercontent.com/28651727/124079851-a09b4280-da84-11eb-87c1-c8e525739628.png>
</div>

RocksDB는 Facebook사에서 개발한 LSM(Log Structured Merge)기반의 No SQL데이터 베이스 저장 엔진입니다.

정보 통신 기술의 발전으로 전 세계의 데이터 생산량이 기하 급수적으로 증가하였고, 이에따라 기존의 관계형 데이터베이스(RDBMS)보다 대용량의 데이터를 효율적으로 저장하고 관리할 수 있는 기술이 중요해 졌고 이에따라 No SQL데이터 베이스가 등장하게 되었습니다. 

NoSQL데이터 베이스는 다음의 몇가지 특징을 가집니다.
- Dynamic Schema
  - RDBMS에서는 데이터베이스에 데이터를 저장하기 전에 사전에 스키마를 정의하여야 합니다. 반면 NoSQL의 경우 사전 정의된(pre-defined) 스키마를 요구하지 않아 데이터 및 요구 사항이 변경됨에 따라 NoSQL 데이터베이스를 훨씬 쉽게 업데이트할 수 있습니다. 
- Data structure
  - RDBMS가 테이블 기반인 반면 NoSQL데이터베이스의 경우 document based, graph databases, key-value pairs, 또는 wide-column stores가 될 수 있습니다. 때문에 더 자유롭게 [`비정형 데이터`](https://www.mongodb.com/unstructured-data)를 처리할 수 있습니다
- Scaling
  - 수직적 확장이 필요한 RDBMS의 경우 더 비싼 단일 서버를 요구하여 확장 비용이 크지만, NoSQL 데이터베이스의 경우 범용의 값싼 서버를 추가하는것으로 수평적 확장이 가능하여 확장비용이 저렴합니다.

NoSQL데이터 베이스에는 대표적으로 Amazon의 DynamoDB, MongoDB, Github의 Redis, Google의 LevelDB 그리고 Facebook의 RocksDB가 있습니다. 그중 RocksDB는 Google에서 개발한 LevelDB를 fork하여 Facebook에서 개발한 오픈소스 프로젝트로 고성능 저장장치에 최적화된 Key-Value 데이터베이스입니다.

## RocksDB Architecture
![image](https://user-images.githubusercontent.com/28651727/124079742-806b8380-da84-11eb-8aa4-fc306c967f27.png)

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

- NoSQL vs Relational Databases : https://www.mongodb.com/scale/nosql-vs-relational-databases
- Cao, Z., Dong, S., Vemuri, S., & Du, D. H. (2020). Characterizing, modeling, and benchmarking rocksdb key-value workloads at facebook. In 18th {USENIX} Conference on File and Storage Technologies ({FAST} 20) (pp. 209-223).
- Dong, S., Callaghan, M., Galanis, L., Borthakur, D., Savor, T., & Strum, M. (2017, January). Optimizing Space Amplification in RocksDB. In CIDR (Vol. 3, p. 3).
- 안미진, 오기환, 강운학, 이상원. (2014). RocksDB의 동기화 성능 비교. 한국정보과학회 학술발표논문집, (), 1516-1518.
- 박연수, 오기환, 이종백, 강운학, 이상원. (2014). 동기화 옵션에 따른 RocksDB 성능 평가. 한국정보과학회 학술발표논문집, (), 1731-1733.
- 신승연, 안미진, 이상원. (2017). RocksDB 컴팩션의 병합패턴 분석. 한국정보과학회 학술발표논문집, (), 1685-1687.
- 김화정, 염헌영, 손용석. (2020). 고성능 컴퓨팅 시스템에서의 RocksDB 병렬성 증대를 위한 최적의 자원 할당 기법. 정보과학회 컴퓨팅의 실제 논문지, 26(3), 144-149.
- 신승연, 안미진, 이상원. (2017). RocksDB 컴팩션시 파일 간 키 범위 중첩 분석. 한국정보과학회 학술발표논문집, (), 1726-1728.