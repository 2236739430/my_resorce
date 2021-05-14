#include "stack1.h"

void swatch(int* a, int* b)
{
	int tem = *a;
	*a = *b;
	*b = tem;
}
// 选择排序
void SelectSort(int* a, int n)//找出遍历最大最小的位，交换，去除最大最小位再遍历
{
	int left = 0;
	int right = n - 1;

	while (left < right)
	{
		int min = left;
		int max = left;
		for (int i = left; i <= right; i++)
		{
			if (a[i] > a[max])
			{
				max = i;
			}
			if (a[i] < a[min])
			{
				min = i;
			}
		}
		swatch(a + left, a + min);
		if (left == max)
		{
			max = min;
		}
		swatch(a + right, a + max);
		left++;
		right--;
	}
}


// 堆排序
void AdjustDown(int* a, int parent, int sz)//升序建大堆
{
	int child = parent * 2 + 1;
	while (child < sz)
	{
		int rightchild = child + 1;
		if (rightchild < sz && a[child] < a[rightchild])
		{
			child = rightchild;
		}
		if (a[child] > a[parent])
		{
			swatch(a + child, a + parent);
		}
		else
		{
			break;
		}
		parent = child;
		child = parent * 2 + 1;
	}
}
void HeapSort(int* a, int n)
{
	while (n > 0)
	{
		for (int i = (n - 1) / 2; i >= 0; i--)
		{
			AdjustDown(a, i, n);
		}
		swatch(a, a + n - 1);
		n--;
	}
}
// 插入排序N^2
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (a[j - 1] > a[j])
			{
				swatch(a + j - 1, a + j);
			}
		}
	}
}

// 希尔排序0（N^1.3)
void ShellSort(int* a, int n)//gap间隔分组排序gap次
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tem = a[end + gap];
			while (end >= 0)
			{
				if (tem < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tem;
		}
	}

}

// 冒泡排序
void BubbleSort(int* a, int n)
{
	for (int i = n - 1; i > 0; i--)
	{
		for (int j = n - 1; j >= n - i; j--)
		{
			if (a[j - 1] > a[j])
			{
				swatch(a + j - 1, a + j);
			}
		}
	}

}


// 快速排序递归实现
int mid(int* a, int left, int right)
{
	int mid = (left + right) / 2;
	if (a[mid] > a[left])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else
		{
			if (a[right] > a[left])
			{
				return right;
			}
			else
			{
				return left;
			}
		}
	}
	else
	{
		if (a[left] > a[right])
		{
			return right;
		}
		else
		{
			return left;
		}
	}
}
// 快速排序hoare版本
int PartSort1(int* a, int left, int right)
{
	int midd = mid(a, left, right);//三点取中
	swatch(a + midd, a + left);
	int key = left;
	while (left < right)
	{
		while (left < right && a[right] >= a[key])
		{
			right--;
		}
		while (left < right && a[left] <= a[key])
		{
			left++;
		}

		swatch(a + left, a + right);//大小交换，相遇退出，并把key换到相遇点
	}
	swatch(a + key, a + left);
	return left;
}
// 快速排序挖坑法
int PartSort2(int* a, int left, int right)
{
	int key = a[left];//必须找个替代变量不然被坑填了
	int hole = left;//确定坑
	while (left < right)
	{
		while (left < right && a[right] >= key)
		{
			right--;
		}
		if (left < right)//右找到小把土挖进坑，自己位置变成坑
		{
			swatch(a + hole, a + right);
			hole = right;
			right--;
		}
		while (left < right && a[left] <= key)
		{
			left++;
		}
		if (left < right)//左找到小把土挖进坑，自己位置变成坑
		{
			swatch(a + hole, a + left);
			hole = left;
			left--;
		}
	}
	a[hole] = key;//把key入坑
	return left;
}

int PartSort3(int* a, int left, int right)
{
	int key = left;
	while (left < right)
	{
		while (left < right && a[right] >= a[key])
		{
			right--;
		}
		while (left < right && a[left] <= a[key])
		{
			left++;
		}

		swatch(a + left, a + right);//大小交换，相遇退出，并把key换到相遇点
	}
	swatch(a + key, a + left);
	return left;
}
void QuickSort(int* a, int left, int right)
{
	if ((right - left) < 1)
	{
		return;
	}
	int meet = PartSort4(a, left, right);//前序
	//int meet = PartSort3(a,left, right);

	QuickSort(a, left, meet - 1);
	QuickSort(a, meet + 1, right);
}
// 快速排序前后指针法
int PartSort4(int* a, int left, int right)
{
	int midd = mid(a, left, right);//三点取中
	swatch(a + midd, a + left);
	int cur = left + 1;
	int pre = left;
	int key = left;
	while (cur <= right)
	{
		if (a[key] > a[cur] && ++pre != cur)
		{
			swatch(a + pre,a + cur);
		}
		cur++;
	}
	swatch(a + key,a + pre);
	return pre;
}


// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right)
{
	Stack aa;
	StackInit(&aa);
	StackPush(&aa, right);//存入左右边界
	StackPush(&aa, left);

	while (left < right)
	{
		left = StackTop(&aa);//取出边界
		StackPop(&aa);
		right = StackTop(&aa);
		StackPop(&aa);

		int meet = PartSort2(a, left, right);//一次排序并得到相遇点

		if (left < meet)//当不是只有一个点时，继续存边界，下次取出再排
		{
			StackPush(&aa, meet - 1);
			StackPush(&aa, left);
		}

		if (right > meet)//类似
		{
			StackPush(&aa, right);
			StackPush(&aa, meet + 1);
		}
	}
}

//归并递归
void mergesort(int* a, int left, int right,int* tem)//把数组拆分为一半一半直到只有一位时返回
{
	if (left == right)                              //从中间分左右两区间，左右区间比大小，小的放入tem，最后得到小区间有序copy回原数组
	{
		return;
	}
	int mid = (left + right) / 2;
    
	mergesort(a,left,mid,tem);
	mergesort(a, mid + 1,right,tem);
	int midd = mid + 1;
	int i = left;
	while (left <= mid && midd <= right)
	{
		if (a[left] < a[midd])
		{
			tem[i++] = a[left];
			left++;
		}
		else
		{
			tem[i++] = a[midd];
			midd++;
		}
	}
	while (left <= mid)
	{
		tem[i++] = a[left++];
	}
	while (midd <= right)
	{
		tem[i++] = a[midd++];
	}
	for (int j = i - 1; j >= 0; j--)
	{
		a[j] = tem[j];
	}

}
// 归并排序递归实现
void MergeSort(int* a, int begin1, int begin2,int end1,int end2,int* tem)
{
	if (begin1 == begin2)
	{
		return;
	}
	int i = begin1;
	int j = begin1;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tem[i++] = a[begin1++];
		}
		else
		{
			tem[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tem[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tem[i++] = a[begin2++];
	}
	for (int aa = j; aa <= end2; aa++)
	{
		a[aa] = tem[aa];
	}
}


// 归并排序非递归实现
void MergeSortNonR(int* a, int n)
{
	int* tem = (int*)malloc(sizeof(int)*n);
	memset(tem,0,sizeof(int)*n);
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, begin2 = i + gap, end1 = i + gap - 1, end2 = i + 2 * gap - 1;
			if (begin2 >= n)//如果第一区间不完整，且第二区间不存在，不排
			{
				break;
			}
			if (end2 >= n)//如果第二区间存在但是不完整，修改边界
			{
				end2 = n - 1;
			}
			MergeSort(a,begin1,begin2,end1,end2,tem);
		}
		gap *= 2;
	}
	free(tem);
}

// 计数排序
void CountSort(int* a, int n)
{
	int max = a[0];
	int min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	int temsize = max - min + 1;
	int* tem = (int*)malloc(sizeof(int) * temsize);
	memset(tem,0,sizeof(int) * temsize);
	for (int i = 0; i < n; i++)
	{
		tem[a[i] - min]++;
	}
	int j = 0;
	for (int i = 0; i < temsize; i++)
	{
		while (tem[i]--)
		{
			a[j++] = i + min;
		}
	}
	free(tem);
}


int main()
{
	int a[] = { 55, 3, 4, 55, 8, 9, 7, 6, 2, 8 ,10};
	//SelectSort(a, sizeof(a) / sizeof(a[0]));
	//HeapSort(a, sizeof(a) / sizeof(a[0]));
	//InsertSort(a, sizeof(a) / sizeof(a[0]));
	//ShellSort(a, sizeof(a) / sizeof(a[0]));
	//BubbleSort(a, sizeof(a) / sizeof(a[0]));
	//QuickSort(a, 0, (sizeof(a) / sizeof(a[0])) - 1);
	//QuickSortNonR(a, 0, (sizeof(a) / sizeof(a[0])) - 1);
	//int* tem = (int*)malloc(sizeof(int)*(sizeof(a) / sizeof(a[0])));
	//mergesort(a, 0, (sizeof(a) / sizeof(a[0])) - 1,tem);
	//MergeSortNonR(a, sizeof(a) / sizeof(a[0]));
	CountSort(a, sizeof(a) / sizeof(a[0]));

	return 0;
}