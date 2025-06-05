class Main
{
    public static void main(String[] args) 
    {
        int num = Integer.parseInt(args[0]);
        int count = 0;

        for (int i = 2; i <= num; i++) 
        {
            boolean isPrime = true;

            for (int j = 2; j <= Math.sqrt(i); j++) 
            {
                if (i % j == 0) 
                {
                    isPrime = false;
                    break;
                }
            }

            if (isPrime)
                count++;
        }

        System.out.println("There are " + count + " prime numbers till " + num);
    }
}
