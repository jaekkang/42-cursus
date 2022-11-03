# access 함수
> 파일 권한 체크 함수 </br>
> #include <unistd.h> </br>
> int access(const char *pathname, int mode) </br>

모드 옵션 </br>
  R_OK : 파일 존재 여부, 읽기 권한 여부 </br>
  W_OK : 파일 존재 여부, 쓰기 권한 여부 </br>
  X_OK : 파일 존재 여부, 실행 권한 여부 </br>
  F_OK : 파일 존재 여부만. </br>

  뒷 부분의 형식이 (mode의) int 이지만 비트연산 ( | )을
  통해서 여러 조건을 한번에 체크할 수 있다.
> access("test.txt", R_OK | W_OK) 처럼

# open 함수

 함수에서 외부 다른 파일을 사용할 때 사용하는 함수 </br>
파일열기에는 표준 함수인 fopen()이 있음.</br> fopen > C 표준 </br>
open() > 리눅스 제공</br>

> #include <fcntl.h> </br>
> int open (const char *FILENAME, int FLAGS[, mod_t MODE]) </br>
인수 </br>
> FILENAME : 대상 파일 이름 </br>
> FLAGS : 파일에 대한 열기 옵션 </br>
> [, mod_t MODE] O_CREATE : 옵션 사용에 의해 파일이 생성될 떄 지정되는 파일 접근 권한 </br>

> return > int 0 : 성공하면 fd값 리턴 , </br> -1 == 실패 </br>

모드 옵션
  O_RDONRY : 읽기 전용 </br>
  
  O_WRONRY : 쓰기 전용 </br>
  
  O_RDWR : 읽기 쓰기 모두 </br>
  
  O_CREAT : open하려는 함수가 없으면 생성함, 짝궁으로 권한 값을 같이 줘야됨 </br>
  
 >위 3개는 open 함수 쓸때 기본적으로 사용되는 옵션 </br>
 >이후 아래 옵션들은 필요에 따라 사용됨, </br>
 >
  O_EXCL : O_CREAT를 사용했을 때 파일이 이미 열려있어도 열기가 가능, 쓰기를 하면 이전 내용이 사라짐, </br> O_CREAT를 O_EXCL과 함께 사용하면 open 취소,</br>
  
  O_TRUNC : 기존 파일의 내용을 모두 삭제 </br>
  
  O_APPEND : 파일을 추가하여 쓰기가 되도록 open 후에 쓰기 포인터가 파일의 끝에 위치하게 됩니다. </br>
  
  O_NOCITTY : 열기 대상이 터미널일 경우, 이 터미널이 프로그램의 제어 터미널에 해당하지 않습니다. </br>
  
  O_NONBLOCK : 읽을 내용이 없을 때에는 읽을 내용이 있을 때까지 기다리지 않고, 바로 복귀합니다. </br>
  
  O_SYNC : 쓰기를 할 때 실제 쓰기가 완료될 떄까지 기다립니다. 즉 물리적으로 쓰기가 완료되어야 복귀가 됩니다. </br>
  
# close 함수

> open() 함수로 열기한 파일을 사용 중지합니다. open() 함수는 fcntl.h에 정의 되어 있지만, write(), read(), close() 는 unistd.h에 선언되어 있습니다. </br>

> #include <unistd.h> </br>
> 인수 : 파일 디스크립터 (int) </br>
> 반환 : 0 == 정상, -1 == close 실패 </br>

# read 함수

> open() 함수로 열기한 파일의 내용을 읽기 합니다. </br>
> ssize_t read (int fd, void *buf, size_t nbytes) </br>
> 인수 : fd (int) , buf (파일을 읽어 들일 버퍼), nbytes (버퍼의 크기) </br>

> 리턴 : ssize_t == -1 실패 , ret == 0 > 정상적으로 실행되었다면 읽어들인 바이트 수 </br>

# wait 함수

> 부모 프로세스가 fork()함수를 사용하여 자식 프로세스를 생성하였을 떄, fork()함수가 리턴되는 시점부터 2개의 프로세스가 동작하게 됩니다.</br>
부모 프로세스가 자식 프로세스의 종료 상태를 얻기 위해서는 wait()함수를 사용합니다. </br>

> #include <sys/wait.h> </br>
> pid_t wait(int *static) </br>
> return : 성공시 프로세스 id 반환, 오류시 -1 </br>


# waitpid 함수

waitpid 함수는 wait 함수처럼 자식 프로세스를 기다릴때 사용하는 함수, 자식 프로세스의 종료 상태를 회수할 때 사용. </br>
wait과의 차이는 자식프로세스가 종료될 때 까지 차단되는 것을 원하지 않을 경우, 옵션을 사용하여 차단을 방지할 수있음. </br>
그리고 기다릴 자식 프로세스를 좀더 상세히 지정가능 </br>

> #include <sys/wait.h> </br>
> pid_t waitpid(pid_t pid, int *static, int options) </br>
> return : 성공시 ID, 오류시 -1 </br>

# pipe 함수

일단, 파이프란 프로세스간 통신을 할 때 사용하는 커뮤니케이션의 한 방법. 

> #include <unistd.h> </br>
> int pipe(int fd[2]); </br>
> return : 성공시 0, 실패시 -1 </br>
> 인자 fd는 2개의 원소가 있는 배열임 fd[0] 읽기용 fd[1]은 쓰기용 </br>
