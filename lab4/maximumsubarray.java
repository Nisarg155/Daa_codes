import java.util.Scanner;
import java.lang.Math;

class calculation{

    int maxsum(int [] arr, int low , int mid , int high)
    {
        int left_sum = Integer.MIN_VALUE;
        int sum = 0;

        for(int i = mid ;i>= low ;i--)
        {
            sum += arr[i];
            if(sum > left_sum)
            {
                left_sum = sum;
            }
        }

        sum = 0;
        int right_sum = Integer.MIN_VALUE;

        for(int i = mid +1 ;i<=high;i++)
        {
            sum += arr[i];
            if(sum > right_sum)
            {
                right_sum = sum;
            }
        }

        return Math.max(left_sum + right_sum , Math.max(left_sum , right_sum));
    }


    int max_subarray(int [] arr , int low , int high )
    {
        if(low ==high ) return arr[low];

        int mid = (low + high)/2;
        return Math.max(max_subarray(arr,low,mid),Math.max(max_subarray(arr,mid+1,high),maxsum(arr,low,mid,high)));

    }
}

class MaxSubarray{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int []arr = new int[n];

        for(int i=0; i<n; i++){
            System.out.print("Enter the element at index " + (i + 1) +  " :- ");
            arr[i] = sc.nextInt();
        }
        calculation obj = new calculation();
        System.out.print("Maximum subarray sum is :- " + obj.max_subarray(arr,0,n-1) + "\n");
    }
}
