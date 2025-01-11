class Solution {
    public int findMin(int[] arr) {
        
        int start = 0;
        int end = arr.length - 1;

        if(arr.length == 1){
            return arr[0];

        }else if(arr[0] < arr[end]){
            return arr[0];
        }

        while(start <= end){
            int mid = start + (end - start) / 2;

            if(mid != 0 && arr[mid - 1] > arr[mid]){
                return arr[mid];

            }else if(mid != arr.length - 1 && arr[mid] > arr[mid + 1]){
                return arr[mid + 1];

            }else if(arr[start] <= arr[mid]){
                start = mid + 1;

            }else{
                end = mid - 1;
            }
        }
        return -1;
    }
}