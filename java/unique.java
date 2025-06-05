import java.util.Scanner;

class UniqueArray
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int[] arr = new int[5];
        int count = 0;

        for(int i = 0; i < 5; i++)
        {
            System.out.print("Enter a number: ");
            int num = sc.nextInt();
            boolean isUnique = true;

            for(int j = 0; j < count; j++)
            {
                if(arr[j] == num)
                {
                    isUnique = false;
                    break;
                }
            }

            if(isUnique)
            {
                arr[count] = num;
                count++;
            }
        }

        sc.close();

        System.out.println("Unique numbers entered:");
        for(int i = 0; i < count; i++)
        {
            System.out.print(arr[i] + " ");
        }
    }
}
