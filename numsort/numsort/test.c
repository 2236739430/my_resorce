#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swatch(int* a, int* b)
{
	int tem = *a;
	*a = *b;
	*b = tem;
}
// ѡ������
void SelectSort(int* a, int n)//�ҳ����������С��λ��������ȥ�������Сλ�ٱ���
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


// ������
void AdjustDown(int* a, int parent, int sz)//���򽨴��
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
// ��������N^2
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (a[j - 1] > a[j])
			{
				swatch(a + j - 1,a + j);
			}
		}
	}
}

// ϣ������0��N^1.3)
void ShellSort(int* a, int n)//gap�����������gap��
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

// ð������
void BubbleSort(int* a, int n)
{
	for (int i = n - 1; i > 0; i--)
	{
		for (int j = n - 1; j >= n - i; j--)
		{
			if (a[j - 1] > a[j])
			{
				swatch(a + j - 1,a + j);
			}
		}
	}

}


// ��������ݹ�ʵ��
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
// ��������hoare�汾
int PartSort1(int* a, int left, int right)
{
	int midd = mid(a,left,right);
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

		swatch(a + left, a + right);//��С�����������˳�������key����������
	}
	swatch(a + key, a + left);
	return left;
}
// ���������ڿӷ�
int PartSort2(int* a, int left, int right)
{
	int key = a[left];//�����Ҹ����������Ȼ��������
	int hole = left;//ȷ����
	while (left < right)
	{
		while (left < right && a[right] >= key)
		{
			right--;
		}
		if (left < right)//���ҵ�С�����ڽ��ӣ��Լ�λ�ñ�ɿ�
		{
			swatch(a + hole,a + right);
		    hole = right;
			right--;
		}
		while (left < right && a[left] <= key)
		{
			left++;
		}
		if (left < right)//���ҵ�С�����ڽ��ӣ��Լ�λ�ñ�ɿ�
		{
			swatch(a + hole, a + left);
			hole = left;
			left--;
		}
	}
	a[hole] = key;//��key���
	return left;
}
// ��������ǰ��ָ�뷨
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
		
		swatch(a + left, a + right);//��С�����������˳�������key����������
	}
	swatch(a + key, a + left);
	return left;
}
void QuickSort(int* a, int left, int right)
{
	if ((right - left ) < 1)
	{
		return;
	}
	int meet = PartSort1(a, left, right);
	//int meet = PartSort3(a,left, right);
	
	QuickSort(a,left,meet - 1);
	QuickSort(a, meet + 1,right);
}

// �������� �ǵݹ�ʵ��
void QuickSortNonR(int* a, int left, int right);

int main()
{
	int a[] = {1,3,4,8,9,7,6,2,8};
	//SelectSort(a, sizeof(a) / sizeof(a[0]));
	//HeapSort(a, sizeof(a) / sizeof(a[0]));
	//InsertSort(a, sizeof(a) / sizeof(a[0]));
	//ShellSort(a, sizeof(a) / sizeof(a[0]));
	//BubbleSort(a, sizeof(a) / sizeof(a[0]));
	QuickSort(a,0, (sizeof(a) / sizeof(a[0])) - 1);

	return 0;
}