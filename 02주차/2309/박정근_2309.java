import java.util.Arrays;
import java.util.Scanner;

//난쟁이를 7명만 뽑으면 되기 때문에 count로 세면서 7일 때 sum이 100이면 출력해주면 됩니다.

public class BOJ2309 {
	static int[] person = new int[10];
	static int[] visit = new int[8]; 
	static boolean isPrint = false;
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		for(int i=1; i<10; i++) 
			person[i] = sc.nextInt();
		
		Arrays.sort(person);
		visit[0] = 0;
		dfs(0, 0);
	}
	
	private static void dfs(int sum,int count){
		if(count == 7) {
			if(!isPrint && sum == 100) {
				for(int i=1; i<8; i++) {
					System.out.println(person[visit[i]]);
				}
				isPrint = true;
			}
			return;
		}
		for(int i=visit[count]+1; i<10; i++){
			visit[count+1] = i;
			dfs(sum+person[i], count+1);
		}
		return ;
	}
}
