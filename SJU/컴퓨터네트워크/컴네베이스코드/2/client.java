package Smtp.project;

import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.Scanner;


public class client {

    private static boolean isValidEmailAddress(String email) {
        String regex = "^[A-Za-z0-9+_.-]+@(.+)$";
        return email.matches(regex);
    }

    public static void main(String[] args) {
        try {
            Socket socket = new Socket("localhost", 5000);// 서버와의 소켓 연결 설정
            DataOutputStream dataOutputStream = new DataOutputStream(socket.getOutputStream());// 데이터 출력 스트림 생성

            // 사용자로부터 이메일 주소와 내용을 입력 받음
            Scanner scanner = new Scanner(System.in);
            System.out.println("받는 사람의 이메일을 입력하세요: ");
            if (!isValidEmailAddress(recipientEmail)) {
                System.out.println("유효하지 않은 이메일 주소입니다.");
                return;  // 메인 메서드 종료 및 이메일 전송 중지
            }
            System.out.println("참조 메일을 입력하세요: ");
            String ccEmail = scanner.nextLine();
            if (!isValidEmailAddress(ccEmail) && !ccEmail.isEmpty()) {
                System.out.println("유효하지 않은 참조 이메일 주소입니다.");
                return;  // 메인 메서드 종료 및 이메일 전송 중지
            }
            String recipientEmail = scanner.nextLine();
            System.out.println("이메일 내용을 입력하세요: ");
            String emailContent = scanner.nextLine();
            System.out.println("첨부 파일 경로를 입력하세요 (또는 빈 문자열 입력): ");
            String attachmentPath = scanner.nextLine();

            // 서버로 이메일 주소와 내용을 전송
            dataOutputStream.writeUTF(recipientEmail);
            dataOutputStream.writeUTF(ccEmail);
            dataOutputStream.writeUTF(emailContent);
            dataOutputStream.writeUTF(attachmentPath); // 첨부 파일 경로도 전송

            // 스트림과 소켓 연결 닫음
            dataOutputStream.close();
            socket.close();
            scanner.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
