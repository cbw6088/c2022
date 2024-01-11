package Smtp.project;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Properties;

import javax.activation.*;
import javax.mail.*;
import javax.mail.internet.*;

public class server {

    public static void main(String[] args) {
        try {
            try (ServerSocket serverSocket = new ServerSocket(5000)) { // 서버 소켓 생성 및 포트 5000으로 설정
                System.out.println("서버가 시작되었습니다. 클라이언트로부터 메시지를 기다립니다.");

                while (true) {
                    Socket socket = serverSocket.accept();// 클라이언트로부터 소켓 연결을 받음
                    DataInputStream dataInputStream = new DataInputStream(socket.getInputStream());// 데이터 입력 스트림 생성

                    // 클라이언트로부터 이메일 주소와 내용을 읽어옴
                    String recipientEmail = dataInputStream.readUTF();
                    String emailContent = dataInputStream.readUTF();
                    String attachmentPath = dataInputStream.readUTF(); // 첨부 파일 경로도 받음
                    String ccEmail = dataInputStream.readUTF();  // 참조(cc) 이메일 주소 추가

                    // 이메일 보내는 메서드 호출
                    sendEmail(recipientEmail, ccEmail, emailContent, attachmentPath);

                    // 소켓 연결 닫음
                    socket.close();
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void sendEmail(String recipientEmail, String ccEmail, String emailContent, String attachmentPath) {
        final String username = "example@gmail.com"; // 보내는 사람 이메일
        final String password = "wqxq eepg wdfp bfou"; // 보내는 사람 이메일의 앱 비밀번호

        Properties props = new Properties();
        props.put("mail.smtp.auth", "true");
        props.put("mail.smtp.starttls.enable", "true");
        props.put("mail.smtp.host", "smtp.gmail.com"); // Gmail SMTP 서버
        props.put("mail.smtp.port", "587"); // TLS 포트
        props.put("mail.smtp.ssl.protocols", "TLSv1.2");

        Session session = Session.getInstance(props,
                new Authenticator() {
                    protected PasswordAuthentication getPasswordAuthentication() {
                        return new PasswordAuthentication(username, password);
                    }
                });

        try {
            Message message = new MimeMessage(session);
            message.setFrom(new InternetAddress(username));
            message.setRecipients(Message.RecipientType.TO,
                    InternetAddress.parse(recipientEmail));
            if (!ccEmail.isEmpty()) { // 참조(cc) 이메일 주소 설정 추가
                message.setRecipients(Message.RecipientType.CC, InternetAddress.parse(ccEmail));
            }
            message.setSubject("Java SMTP 메일 테스트");
            
            
            // 첨부 파일 추가
            if (!attachmentPath.isEmpty()) {
                BodyPart attachmentPart = new MimeBodyPart();
                FileDataSource source = new FileDataSource(attachmentPath);
                attachmentPart.setDataHandler(new DataHandler(source));
                attachmentPart.setFileName(new File(attachmentPath).getName());
                
                Multipart multipart = new MimeMultipart();
                multipart.addBodyPart(attachmentPart);

                // 메시지 본문 설정
                BodyPart messageBodyPart = new MimeBodyPart();
                messageBodyPart.setText(emailContent);

                multipart.addBodyPart(messageBodyPart);
                message.setContent(multipart);
                
            }
            else {
            	message.setText(emailContent);
            }


            Transport.send(message);

            System.out.println("이메일 전송 완료");

        } catch (MessagingException e) {
            throw new RuntimeException(e);
        }
    }
}
