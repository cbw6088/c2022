## <strong>Flask</strong>
- Python의 대표적인 웹 프레임워크로 적은 노력으로 많은 작업을 할 수 있는 도구

### <strong>기본 세팅</strong>
- 코드 실행 시 해당 사이트에 가면 'hi'가 출력되어 있다.
- debug = True를 준 이유는, 수정되는 값을 그때 그때 자동으로 처리하기 위함이다.
- return값은 문자열 값이어야 한다.
- 즉, 함수 및 주소를 반환 할 땐 str(함수 및 주소)함수를 이용한다.
```py
from flask import Flask

app = Flask(__name__)

@app.route('/')
def index():
    return 'hi'

app.run(port = 5001, debug = True)
```
### <strong>라우팅(Routing)</strong>
- 생성, 읽기, 쓰기 등등의 각각의 주소들이 입력해서 들어오는 요청을 처리하는 함수와 연결하는 작업을 <strong>라우팅</strong>이라고 한다.
```py
# 예시
@app.route('/') # 사용자가 패스를 입력하지 않고('/') 접속하면  
def index(): # index라는 함수와 연결된다 라는 의미이고, 이것을 라우팅이라고 한다.
    return 'hi' # 해당 주소의 출력 값

@app.route('/hello/') # 사용자가 패스를 '/hello'라고 입력해서 접속하면 
def hello(): # hello라는 함수와 연결된다 라는 의미이고, 이것을 라우팅이라고 한다.
    return 'Hello' # 해당 주소의 출력 값

@app.route('/create/1/') # 사용자가 패스를 '/create/1/'라고 입력해서 접속하면 (더 상세한 주소)
def create(): # create라는 함수와 연결된다 라는 의미이고, 이것을 라우팅이라고 한다.
    return 'Create 1' # 해당 주소의 출력 값

@app.route('/read/<id>/') # 사용자가 패스를 '/create/<id>/'라고 입력해서 접속하면 (<id>라는 값의 주소로 전달 됨(id 변수는 변경 가능))
def read(id): # read라는 함수와 연결된다 라는 의미이고, 이것을 라우팅이라고 한다. (위에서 받은 id 인자로 받아야 함)
    return 'Read ' + id # 해당 주소의 출력 값
```

### <strong>사이트 제작 예시</strong>
```py
from flask import Flask
import random

app = Flask(__name__)

topics = [ # 리스트를 이용하여 제작 (각 리스트 안의 내용 포함)
    {'id' : 1, 'title' : 'html', 'body' : 'html is . . .'},
    {'id' : 2, 'title' : 'css', 'body' : 'css is . . .'},
    {'id' : 3, 'title' : 'javascript', 'body' : 'javascript is . . .'}
]

def template(contents, content) : # 반복되는 코드 함수로 묶기
    return f'''<!doctype html>
    <html>
        <body>
            <h1><a href = "/">WEB</a></h1>
            <ol>
                {contents}
            </ol>
            {content}
        </body>
    </html>
    '''

def getContents() : # 반복되는 코드 함수로 묶기
    liTags = ''
    for topic in topics :
        #<a>를 이용하여 링크 참조, /read/는 링크를 누를 시 주소(따로 만들어야 함)
        liTags = liTags + f'<li><a href ="/read/{topic["id"]}/">{topic["title"]}</a></li>' # f는 변수를 편하게 쓰기위한 도구 
    return liTags

@app.route('/')
def index():
    return template(getContents(), '<h2>Welcome</h2>Hello, WEB')

@app.route('/read/<int:id>/')
def read(id):
    title = ''
    body = ''
    for topic in topics :
        if id == topic['id'] :
            title = topic['title']
            body = topic['body']
            break
    return template(getContents(), f'<h2>{title}</h2>{body}')

app.run(port = 5001, debug = True)
```
### <strong></strong>
### <strong></strong>
### <strong></strong>
### <strong></strong>
### <strong></strong>
### <strong></strong>
### <strong></strong>
### <strong></strong>
### <strong></strong>
### <strong></strong>
### <strong></strong>
### <strong></strong>
### <strong></strong>
### <strong></strong>
### <strong></strong>
### <strong></strong>
### <strong></strong>
### <strong></strong>
### <strong></strong>
