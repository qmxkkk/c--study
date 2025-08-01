#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) 
//{
//    int mid = (nums1Size + nums2Size) / 2 ;
//    int log = 2, e_log = 2;
//    int an = 0;
//    int num[1001] = { 0 };
//    int i = 0, j = 0;
//    if (nums1Size == 0 || nums2Size == 0)
//        return nums2Size ? (nums2Size % 2 ? nums2[nums2Size / 2] : (nums2[nums2Size / 2 - 1] + nums2[nums2Size / 2]) / 2.0) : 
//        (nums1Size % 2 ? nums1[nums1Size / 2] : (nums1[nums1Size / 2 - 1] + nums1[nums1Size / 2]) / 2.0);
//    for (; i + j < mid; )
//    {
//        if (nums1[i] <= nums2[j])
//        {
//            i++;
//            e_log = 1;
//        }
//        else
//        {
//            j++;
//            e_log = 0;
//        }
//
//    }
//    
//    int lastn = ((i < nums1Size ? nums1[i] : nums2[j]) < (j < nums2Size ? nums2[j] : nums1[i])) ? nums1[i] : nums2[j];
//    if (e_log)
//    {
//        i--;
//        log = (lastn < nums1[i]) ? 1 : 0;
//    }
//    else
//    {
//        j--;
//
//        log = (lastn < nums2[j]) ? 1 : 0;
//
//    }
//
//
//    if ((nums1Size + nums2Size) % 2)
//    {
//        
//        return log ? lastn : e_log ? nums2[j] : nums1[i];
//    }
//    else
//    {
//        //an += log ? nums2[j] : nums1[i];
//        //an += e_log ? nums1[i - (log == e_log) ? 1 : 0] : nums2[j - (log == e_log) ? 1 : 0];
//        return (e_log ? nums2[j] : nums1[i] + lastn) / 2.0;
//    }
//
//}


//double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
//{
//    int mid = (nums1Size + nums2Size) / 2 + 1;
//    int log = 3, e_log = 3, log1 = 0, log2 = 0, e_log2 = 0;
//    int min = 0, max = 0, e_max = 0, e_min = 0;
//    int c = 0, c_tmax = 0, c_tmin = 0, e_mid = 0, c_mid = 0, c_min = 0;
//    int com1 = 0, com2 = 0;
//    int i = 0, j = 0, i1 = 0, j1 = 0;
//    if (nums1Size == 0 || nums2Size == 0)
//        return nums2Size ? (nums2Size % 2 ? nums2[nums2Size / 2] : (nums2[nums2Size / 2 - 1] + nums2[nums2Size / 2]) / 2.0) : 
//        (nums1Size % 2 ? nums1[nums1Size / 2] : (nums1[nums1Size / 2 - 1] + nums1[nums1Size / 2]) / 2.0);
//    if (nums1Size == 1 && nums2Size == 1)
//    {
//        return (nums1[0] + nums2[0]) / 2.0;
//    }
//    c_mid = nums1[i];
//    e_log2 = 1;
//    i++;
//
//    
//    while ( c < mid )
//    {
//        e_mid = c_mid;
//        e_min = c_min;
//        if (nums1Size == 1 && c == 1 && log == 1)
//        {
//        }
//            i--;
//        if (i < nums1Size && j < nums2Size)
//        {
//            com1 = nums1[i];
//            com2 = nums2[j];
//        }
//        
//        if (i >= nums1Size && j < nums2Size)
//        {
//            if(!log1)
//                j1 = j + 1;
//            log1 = 1;
//            
//            if (j >= nums2Size)
//                com2 = 2147483647;
//            else
//                com2 = nums2[j];
//            if(j1 >= nums2Size)
//                com1 = 2147483647;
//            else
//                com1 = nums2[j1];
//            
//            c_tmax = (com1 > com2) ? com1 : com2;
//            c_tmin = (com1 < com2) ? com1 : com2;
//            e_log = 0;
//
//        }
//        else if (j >= nums2Size && i < nums1Size)
//        {
//            if(!log2)
//                i1 = i + 1;
//            log2 = 1;
//            if (i >= nums1Size)
//                com1 = 2147483647;
//            else
//                com1 = nums1[i];
//            if (i1 >= nums1Size)
//                com2 = 2147483647;
//            else
//                com2 = nums1[i1];
//            c_tmax = (com1 > com2) ? com1 : com2;
//            c_tmin = (com1 < com2) ? com1 : com2;
//            e_log = 1;
//
//        }
//        else if(i >= nums1Size && j >= nums2Size)
//            c_min = c_mid;
//        else if (i < nums1Size && j < nums2Size)
//        {
//            c_tmax = (com1 > com2) ? com1 : com2;
//            c_tmin = (com1 < com2) ? com1 : com2;
//            e_log = (com1 < com2) ? 1 : 0;
//        }
//        
//
//        
//        if (c_mid < c_tmin)
//        {
//            c_min = c_mid;
//            c_mid = c_tmin;
//            e_log2 = e_log;
//            log = 2;
//            if (e_log2)
//                i++;
//            else
//                j++;
//            c++;
//        }
//        else if(c_mid <c_tmax)
//        {
//            c_min = c_tmin;
//            log = 0;
//            if (e_log)
//                i++;
//            else
//                j++;
//            c++;
//        }
//        else
//        {
//            c_min = c_tmin;
//            c_mid = c_tmax;
//            e_log2 = !e_log;
//            if (e_log)
//                i++;
//            else
//                j++;
//            log = 1;
//            c++;
//        }
//
//        if (c < mid)
//        {
//            if (log1)
//                j1++;
//            else if (log2)
//                i1++;
//        }
//
//
//    }
//    
//    
//
//
//
//    if ((nums1Size + nums2Size) % 2)
//        return c_min;
//    else
//        return (c_min + e_min) / 2.0;
//
//}


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
	int i = 0, j = 0, i1 = 0, j1 = 0;
	int mid = (nums1Size + nums2Size) / 2 + 1;
	int c = 0, min = 0, e_min = 0;
	int com1 = 0, com2 = 0, log1 = 0, log2 = 0, log = 0, tlog = 0;

	if (nums1Size == 0 || nums2Size == 0)
        return nums2Size ? (nums2Size % 2 ? nums2[nums2Size / 2] : (nums2[nums2Size / 2 - 1] + nums2[nums2Size / 2]) / 2.0) : 
        (nums1Size % 2 ? nums1[nums1Size / 2] : (nums1[nums1Size / 2 - 1] + nums1[nums1Size / 2]) / 2.0);
    if (nums1Size == 1 && nums2Size == 1)
    {
        return (nums1[0] + nums2[0]) / 2.0;
    }

	while (c < mid)
	{
		e_min = min;
		if (i >= nums1Size && j < nums2Size)
		{
			if (!log1)
				j1 = j + 1;
			com1 = nums2[j];
			com2 = nums2[j1];
			j++;
			j1++;
			tlog = 1;
		}
		else if (j >= nums2Size && i < nums1Size)
		{
			if (!log2)
				i1 = i + 1;
			com1 = nums1[i];
			com2 = nums1[i1];
			i++;
			i1++;
			tlog = 1;
		}
		else
		{
			com1 = nums1[i];
			com2 = nums2[j];
		}
		
		min = (com1 < com2) ? com1 : com2;
		c++;
		log = (com1 < com2) ? 1 : 0;
		
		if (!tlog)
		{
			if (log)
				i++;
			else
				j++;
		}

	}
	if ((nums1Size + nums2Size) % 2)
		return min;
	else
		return (e_min + min) / 2.0;
}

double findMedianSortedArrays2(int* nums1, int nums1Size, int* nums2, int nums2Size)//可行
{
	int i = 0, j = 0, i1 = 0, j1 = 0;
	int mid = (nums1Size + nums2Size) / 2 + 1;
	int c = 0, min = 0, e_min = 0;
	int com1 = 0, com2 = 0, tlog = 0, log = 0;

	if (nums1Size == 0 || nums2Size == 0)
		return nums2Size ? (nums2Size % 2 ? nums2[nums2Size / 2] : (nums2[nums2Size / 2 - 1] + nums2[nums2Size / 2]) / 2.0) :
		(nums1Size % 2 ? nums1[nums1Size / 2] : (nums1[nums1Size / 2 - 1] + nums1[nums1Size / 2]) / 2.0);

	while (c < mid)
	{
		e_min = min;
		if (i >= nums1Size )
		{
			min = nums2[j];
			tlog = 1;
			j++;
		}
		else if (j >= nums2Size )
		{
			min = nums1[i];
			tlog = 1;
			i++;
		}
		else
		{
			com1 = nums1[i];
			com2 = nums2[j];
			min = (com1 < com2) ? com1 : com2;

		}

		c++;
		log = (com1 < com2) ? 1 : 0;

		if (!tlog)
		{
			if (log)
				i++;
			else
				j++;
		}

	}
	if ((nums1Size + nums2Size) % 2)
		return min;
	else
		return (e_min + min) / 2.0;
}

double findMedianSortedArrays3(int* nums1, int nums1Size, int* nums2, int nums2Size)//可行，若下标越界，则直接返回答案
{
	int i = 0, j = 0, i1 = 0, j1 = 0;
	int mid = (nums1Size + nums2Size) / 2 + 1;
	int c = 0, min = 0, e_min = 0;
	int com1 = 0, com2 = 0, tlog = 0, log = 0, t = 0;

	if (nums1Size == 0 || nums2Size == 0)
		return nums2Size ? (nums2Size % 2 ? nums2[nums2Size / 2] : (nums2[nums2Size / 2 - 1] + nums2[nums2Size / 2]) / 2.0) :
		(nums1Size % 2 ? nums1[nums1Size / 2] : (nums1[nums1Size / 2 - 1] + nums1[nums1Size / 2]) / 2.0);

	while (c < mid && tlog == 0)
	{
		e_min = min;

		if (i < nums1Size && j < nums2Size)
		{
			com1 = nums1[i];
			com2 = nums2[j];
			c++;

		}
		min = (com1 < com2) ? com1 : com2;
		log = (com1 < com2) ? 1 : 0;

		if (i >= nums1Size)
			tlog = 1;
		else if (j >= nums2Size)
			tlog = 2;

		if (!tlog)
		{
			if (log)
				i++;
			else
				j++;
		}
	}

	if ((nums1Size + nums2Size) % 2)
	{
		if (tlog==1)
			return nums2[j + mid - c - 1];
		else if(tlog==2)
			return nums1[i + mid - c - 1];

		return min;

	}
	else
	{
		if (tlog == 1)
		{
			t = ((j + mid - c - 2) < 0 ? e_min : nums2[j + mid - c - 2]);
			min = (t > nums1[i - 1]) ? t : nums1[i - 1];
			return ( min + nums2[j + mid - c - 1]) / 2.0;
		}
		else if (tlog == 2)
		{
			t = ((i + mid - c - 2) < 0 ? e_min : nums1[i + mid - c - 2]);

			min = (t > nums2[j - 1]) ? t : nums2[j - 1];
			return (min + nums1[i + mid - c - 1]) / 2.0;
		}

		return (e_min + min) / 2.0;

	}
}

int main()
{
	int nums1[1] = { 1 };
	int nums2[3] = { 2,3,4 };
    printf("%f", findMedianSortedArrays3(nums1, 1, nums2, 3));


	return 0;
}