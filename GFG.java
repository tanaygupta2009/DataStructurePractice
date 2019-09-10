import java.util.*;
class GFG
{
	public static void main(String[] args) 
	{
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		while(t>0)
		{
			int n = in.nextInt();
			int p = 1;
			while(n>0)
			{
				int temp = in.nextInt();
				if(temp!=p)
				{
					System.out.println(p);
					break;
				}
				p++;
				n--;
			}
			t--;
		}
	}
}