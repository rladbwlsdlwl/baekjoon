import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

class NewEmployee{
    public static void main(String[] args) throws IOException {
        // Scanner sc = new Scanner(System.in);
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(bf.readLine());
        while(T-- > 0){
            int N = Integer.parseInt(bf.readLine());
            int[][] people = new int[N][2];

            for(int i=0; i<N; i++){
                String s = bf.readLine();

                people[i][0] = Integer.parseInt(s.split(" ")[0]);
                people[i][1] = Integer.parseInt(s.split(" ")[1]);
            }

            //ascending sort
            Arrays.sort(people, (a, b) -> {
                return a[0] - b[0];
            });
    

            int ans = 1;
            int p = people[0][1];
            for(int i=1; i<N; i++){
                if(people[i][1] < p) {
                    p = people[i][1];
                    ans++;
                }
            }
            
            System.out.println(ans);
        }
    }
}
