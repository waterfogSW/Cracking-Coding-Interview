import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class BJ_2751 {
    static int n;
    static int arr[];
    static int sorted[];

    static BufferedReader br;
    static BufferedWriter bw;

    static private void merge(int left, int mid, int right) {
        int i, j, k;
        i = left;
        j = mid + 1;
        k = left;

        // 정렬된 값 sorted로 이동
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j])
                sorted[k++] = arr[i++];
            else
                sorted[k++] = arr[j++];
        }

        // 남은값 복사
        if (i > mid) {
            for (int l = j; l <= right; l++)
                sorted[k++] = arr[l];
        }
        // 남은값 복사
        else {
            for (int l = i; l <= mid; l++)
                sorted[k++] = arr[l];
        }

        // 정렬된 배열 arr로 복사
        for (int l = left; l <= right; l++) {
            arr[l] = sorted[l];
        }
    }

    static void mergeSort(int left, int right) {
        int mid;

        if (left < right) {
            mid = (left + right) / 2;
            mergeSort(left, mid);
            mergeSort(mid + 1, right);
            merge(left, mid, right);
        }
    }

    public static void main(String[] args) throws Exception {
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        arr = new int[n];
        sorted = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        mergeSort(0, n - 1);

        for (int i = 0; i < n; i++) {
            bw.append(arr[i] + "\n");
        }
        bw.flush();
        bw.close();
    }
}
