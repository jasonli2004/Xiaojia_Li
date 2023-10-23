import java.util.Scanner;
public class ComplexLogic
{
   public static void main(String[] args)
   {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNextInt())
        {
            int num = sc.nextInt();
            if ((num % 2 == 1 || num % 2 == -1) && (num < 0 || num >= 100))
            {
                System.out.println("yes");
            }
            else
            {
                if (num % 3 == 0 || (num >= 0 && num <100)) 
                {
                    System.out.println("maybe");
                }
                else
                {
                    System.out.println("no");
                }
            }
        }
        sc.close();
   }
}

