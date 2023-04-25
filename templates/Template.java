/**
 *  author: josuerom
 * created: 14/01/23 13:30:17
**/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.Collections;
import java.util.ArrayList;

public class Solution {
   public static void main(String[] args) {
      FastScanner fs = new FastScanner();
      PrintWriter pw = new PrintWriter(System.out);
      // Write code here
      pw.flush();
      pw.close();
   }
   
   static final Random random = new Random();
   static final int MOD = 1_000_000_007;
   static final int MAX = 1_000_000_000;
   
   static void ruffleSort(int[] a) {
      int n = a.length;
      for (int i = 0; i < n; i++) {
         int oi = random.readInt(n), temp = a[oi];
         a[oi] = a[i]; a[i] = temp;
      }
      Arrays.sort(a);
   }
   
   static long add(long a, long b) {
      return (a+b) % MOD;
   }
   
   static long sub(long a, long b) {
      return ((a-b) % MOD + MOD) % MOD;
   }
   
   static long mul(long a, long b) {
      return (a*b) % MOD;
   }
   
   static long exp(long base, long exp) {
      if (exp==0) return 1;
      long half=exp(base, exp/2);
      if (exp%2==0) return mul(half, half);
      return mul(half, mul(half, base));
   }
   
   static long[] factorials = new long[2_000_010];
   static long[] invFactorials = new long[2_000_010];
   
   static void precompFacts() {
      factorials[0] = invFactorials[0] = 1;
      for (int i = 1; i < factorials.length; i++) factorials[i] = mul(factorials[i-1], i);
      invFactorials[factorials.length-1] = exp(factorials[factorials.length-1], MOD-2);
      for (int i = invFactorials.length-2; i >= 0; i--) invFactorials[i] = mul(invFactorials[i+1], i+1);
   }
   
   static long nCr(int n, int r) {
      return mul(factorials[n], mul(invFactorials[r], invFactorials[n-r]));
   }
   
   static long nPr(int n, int r) {
      return mul(factorials[n], mul(invFactorials[r], invFactorials[n]));
   }
   
   static class FastScanner {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      StringTokenizer st = new StringTokenizer("");
      
      String next() {
         while (!st.hasMoreTokens()) {
            try { st = new StringTokenizer(br.readLine()); }
            catch (IOException e) { e.printStackTrace(); }
         }
         return st.nextToken();
      }
      
      int readInt() {
         return Integer.parseInt(next());
      }
      long readLong() {
         return Long.parseLong(next());
      }
      int[] readArray(int n) {
         int[] a = new int[n];
         for (int i = 0; i < n; i++) {
            a[i] = readInt();
         }
         return a;
      }
   }
}
