import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;
import java.util.Scanner;

public class Main {

    static String solution(int n, int[] balloon){
        Deque<int[]> dq = new ArrayDeque<>();


        for(int i=0; i<balloon.length; i++)
            dq.add(new int[]{balloon[i], i});

    


        // {풍선에 기록된 거리(이동), 풍선 번호 (idx)}
        int[] point = {1, 0};

        StringBuilder ans = new StringBuilder();
        while(!dq.isEmpty()){

            // 풍선 움직이기
            if(point[0] > 0){ 
                // 오른쪽으로 로테이션 (앞의 원소를 뒤로 이동)
                int move = point[0] - 1;


                // 앞의 원소 뒤로 옮기기
                while(move-- > 0){
                    int[] p = dq.removeFirst();

                    dq.addLast(p);
                }
            }else{
                // 왼쪽으로 로테이션 (뒤의 원소를 앞으로 이동)

                int move = point[0];


                while(move++ < 0){
                    int[] p = dq.removeLast();

                    dq.addFirst(p);
                }
            }
            
    
           

            point = dq.removeFirst();
     
            ans.append(point[1] + 1).append(" ");
        }

        

        return ans.toString();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        
        sc.nextLine();

        String s = sc.nextLine();

        int[] balloon = Arrays.stream(s.split(" "))
            .mapToInt(Integer:: parseInt)
            .toArray();


        System.out.println(solution(N, balloon));

    }
}
