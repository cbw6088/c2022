from flask import Flask, request, jsonify

app = Flask(__name__)

def get_user_location():
    # GPS 관련 기능을 통해 사용자 위치 정보를 얻는 함수
    # 실제 구현은 외부 라이브러리나 서비스와의 연동을 포함할 수 있습니다.
    # 임시로 사용자 위치를 '혼잡지역'으로 설정합니다.
    return '혼잡지역'

@app.route('/', methods=['GET'])
def index():
    return 'Welcome to the congestion checking app!'

@app.route('/check_congestion', methods=['POST'])
def check_congestion():
    # POST 요청에서 이미지 데이터 받기
    image = request.files['image']

    # 여유 공간 계산 (임의의 값 사용)
    total_area = 100
    occupied_area = 60
    free_area = total_area - occupied_area
    free_percentage = (free_area / total_area) * 100

    # 혼잡도 등급 판별
    congestion_level = '원활'
    if free_percentage < 30:
        congestion_level = '혼잡'
    elif free_percentage < 70:
        congestion_level = '보통'

    # GPS 기능
    user_location = get_user_location()

    # 혼잡 알림
    if congestion_level == '혼잡' and user_location == '혼잡지역':
        send_notification('현재 위치가 혼잡합니다.')

    # 설정한 특정 수치 알림 (임의의 값 사용)
    target_percentage = 80
    if free_percentage <= target_percentage:
        send_notification(f'여유 공간이 {target_percentage}% 이하입니다.')

    # 결과 반환
    result = {
        'free_percentage': free_percentage,
        'congestion_level': congestion_level
    }
    return jsonify(result)

if __name__ == '__main__':
    app.run()
