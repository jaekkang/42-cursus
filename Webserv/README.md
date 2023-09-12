# webserv

## 개요

멤버 : jaekkang danpark juyojeon yejinam sungwook myko  
시작일 : 07.03

## 참고 이미지

jaekkang님의 요청으로 추가

### HTTP 멱동성

![http_idempotent](/images/http_idempotent.png)

---

### Message 구조

![method_structure](/images/message_structure.png)

---

### Request 형식

![request_format](/images/request_format.png)

---

### Request 상태 의미

![request_status](/images/request_status.png)

## 참고 문헌

- [42seoul, webserv](reference/webserv.pdf)
- [42seoul, webserv_ko](reference/webserv_ko.md)
- [Webserv tutorials](https://42seoul.gitbook.io/webserv/)

서브젝트에서 RFC를 읽으라고는 되어 있지만 이전처럼 7230 ~ 7235를 읽으라는 문구는 없는 것 같습니다. (확인하시면 수정좀) 그래도 일단 올려놓습니다.

- [RFC 7230](https://www.ietf.org/rfc/rfc7230.txt)
- [RFC 7231](https://www.ietf.org/rfc/rfc7231.txt)
- [RFC 7232](https://www.ietf.org/rfc/rfc7232.txt)
- [RFC 7233](https://www.ietf.org/rfc/rfc7233.txt)
- [RFC 7234](https://www.ietf.org/rfc/rfc7234.txt)
- [RFC 7235](https://www.ietf.org/rfc/rfc7235.txt)

## docker

```shell
cd nginx
docker build -t nginx:test-nginx .
docker run -d -p 80:80 -v $PWD:/nginx nginx:test-nginx
# remove
docker ps # container id
docker stop ${nginx_container_id}
docker rm ${nginx_container_id}
```
