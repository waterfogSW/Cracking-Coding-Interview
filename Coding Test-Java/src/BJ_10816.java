import java.io.*;
import java.util.Arrays;

public class BJ_10816 {
    static int arr1[], arr2[], result[];
    static BufferedReader br;
    static BufferedWriter bw;

    static int n, m;

    static private int bs(int target) {
        int start = 0;
        int end = n - 1;
        int mid = 0;

        while(start < end) {
            mid = (start + end) / 2;
            if(arr1[mid] < target) start = mid + 1;
            else if(arr1[mid] > target) end = mid - 1;
            else break;
        }
        return mid;
    }
    public static void main(String[] args) throws Exception {
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        arr1 = new int[n];
        
        for (int i = 0; i < n; i++) {
            arr1[i] = Integer.parseInt(br.readLine());
        }

        m = Integer.parseInt(br.readLine());

        arr2 = new int[m];
        result = new int[m];

        for(int i = 0; i < m; i++) {
            arr2[i] = Integer.parseInt(br.readLine());
        }

        Arrays.sort(arr1);
        for (int i = 0; i < m; i++) {
            bw.append(bs(arr2[i]) + "\n");
        }
        bw.flush();
        bw.close();

    }
}
