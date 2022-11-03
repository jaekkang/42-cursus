## access 함수
> 파일 권한 체크 함수
> #include <unistd.h>
# int access(const char *pathname, int mode)

R_OK : 파일 존재 여부, 읽기 권한 여부 
W_OK : 파일 존재 여부, 쓰기 권한 여부
X_OK : 파일 존재 여부, 실행 권한 여부
F_OK : 파일 존재 여부만.

뒷 부분의 형식이 (mode의) int 이지만 비트연산 ( | )을
통해서 여러 조건을 한번에 체크할 수 있다.
> access("test.txt", R_OK | W_OK) 처럼

## open 함수

> 함수에서 외부 다른 파일을 사용할 때 사용하는 함수
파일열기에는 표준 함수인 fopen()이 있음. fopen > C 표준
open() > 리눅스 제공

> #include <fcntl.h>
