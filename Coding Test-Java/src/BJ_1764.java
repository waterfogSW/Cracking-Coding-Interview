import java.io.*;
import java.util.*;

public class BJ_1764 {
    static int n, m;
    static String[] nn, mm;
    static ArrayList<String> result = new ArrayList<>();

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    private static Boolean bs(String s) {

        int start = 0;
        int end = n - 1;
        int mid;

        while (start <= end) {
            mid = (start + end) / 2;
            if (nn[mid].compareTo(s) == 0)
                return true;
            else if (nn[mid].compareTo(s) < 0)
                start = mid + 1;
            else
                end = mid - 1;
        }

        return false;
    }

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        nn = new String[n];
        mm = new String[m];

        for (int i = 0; i < n; i++) {
            String tmp = br.readLine();
            nn[i] = tmp;
        }

        for (int i = 0; i < m; i++) {
            String tmp = br.readLine();
            mm[i] = tmp;
        }

        Arrays.sort(nn);

        for (String s : mm) {
            if (bs(s))
                result.add(s);
        }

        Collections.sort(result);

        bw.write(result.size() + "\n");
        for (String s : result) {
            bw.write(s + '\n');
        }
        bw.close();
    }
}
