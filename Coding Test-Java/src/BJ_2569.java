import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class BJ_2569 {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static int n, result;
    public static int[] load;
    public static int[] sorted;

    private static int unsorted_minIdx(int x) {
        int minVal = Integer.MAX_VALUE;
        int minIdx = -1;
        for (int i = x; i < n; i++) {
            if (load[i] < minVal && load[i] != sorted[i]) {
                minVal = load[i];
                minIdx = i;
            }
        }
        return minIdx;
    }

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());

        load = new int[n];
        sorted = new int[n];

        for (int i = 0; i < n; i++) {
            load[i] = Integer.parseInt(br.readLine());
            sorted[i] = load[i];
        }

        Arrays.sort(sorted);

        int minIdx = 0;
        int result = 0;

        minIdx = unsorted_minIdx(0);

        while (true) {
            int idx = -1;

            // 가장 작은값의 인덱스가 0의 위치에 있을때
            // 정렬되지 않은 값중 가장 작은 값과 위치를 변경
            if (minIdx == 0) {
                minIdx = unsorted_minIdx(1);
                
                if (minIdx == -1)
                    break;
                    
                result += load[minIdx];
                result += load[0];

                int tmp = load[minIdx];
                load[minIdx] = load[0];
                load[0] = tmp;
                minIdx = idx;

                continue;
            }

            // 가장 작은 값의 자리에 있어야 할 값을 찾기
            for (int i = 0; i < n; i++) {
                if (load[i] == sorted[minIdx])
                    idx = i;
            }

            if (minIdx == -1)
                break;

            // 해당 값과 변경
            result += load[minIdx];
            result += load[idx];

            int tmp = load[minIdx];
            load[minIdx] = load[idx];
            load[idx] = tmp;
            minIdx = idx;
        }

        System.out.println(result);
    }

}
