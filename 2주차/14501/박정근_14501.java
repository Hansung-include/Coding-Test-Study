import java.io.*;
import java.util.*;

public class BOJ14501 {
    static int N;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        int[] T = new int[N+1+5];
        int[] P = new int[N+1+5];
        int[] dp = new int[N+1+5];

        for(int i=1; i<=N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            T[i] = Integer.parseInt(st.nextToken());
            P[i] = Integer.parseInt(st.nextToken());
        }

        int max = 0;
        for(int i=1; i<=N+1; i++){
            dp[i] = Math.max(max, dp[i]);
            dp[T[i]+i] = Math.max(dp[T[i]+i], dp[i]+P[i]);
            max = Math.max(dp[i], max);
        }
        System.out.println(max);
    }
}