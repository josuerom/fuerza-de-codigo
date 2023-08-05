
/**
 *   author:  josuerom
 *   created: 03/08/23 19:48:11
**/
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class A_Insert_Node {
   static FastReader io = new FastReader();

   public static void main(String[] authorJosuerom) {
      int n = io.nextInt();
      solve(n);
      io.close();
      System.exit(0);
   }

   public static void solve(int n) {
      LinkedList<Integer> list = new LinkedList<>();
      for (int i = 0; i < n; i++) {
         list.add(io.nextInt());
      }
      for (int i = 0; i < n; i++) {
         int aux = list.removeLast();
         io.printf("%d\n", aux);
      }
      io.println();
   }

   static class FastReader extends PrintWriter {
      private BufferedReader br;
      private StringTokenizer st;

      public FastReader() {
         this(System.in, System.out);
      }

      public FastReader(InputStream i, OutputStream o) {
         super(o);
         br = new BufferedReader(new InputStreamReader(i));
      }

      public FastReader(String problemName) throws IOException {
         super(problemName + ".out");
         br = new BufferedReader(new FileReader(problemName + ".in"));
      }

      public String next() {
         try {
            while (st == null || !st.hasMoreTokens())
               st = new StringTokenizer(br.readLine());
            return st.nextToken();
         } catch (Exception e) {
            e.printStackTrace();
         }
         return null;
      }

      public String nextLine() {
         String line = null;
         try {
            line = br.readLine();
         } catch (IOException e) {
            e.printStackTrace();
         }
         return line;
      }

      public int nextInt() {
         return Integer.parseInt(next());
      }

      public long nextLong() {
         return Long.parseLong(next());
      }

      public double nextDouble() {
         return Double.parseDouble(next());
      }

      public int[] readArray(int n) {
         int[] a = new int[n];
         for (int i = 0; i < n; i++) {
            a[i] = io.nextInt();
         }
         return a;
      }
   }
}