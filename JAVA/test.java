import java.util.Scanner;

public class test{
    public static void main(String[] args){
        var num = 10;
        Scanner kb = new Scanner(System.in);
        System.out.print("Please enter an integer : ");
        int input = kb.nextInt();
        if(input == num){
            System.out.println("값이 같음!");
        }
        else{
            System.out.println("값이 같지 않음");
        }
    }
}