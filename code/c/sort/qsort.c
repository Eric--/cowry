#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
��������ʹ�÷��η���Divide and conquer����������һ�����У�list����Ϊ�����Ӵ��У�sub-lists����
����Ϊ��
������������һ��Ԫ�أ���Ϊ "��׼"��pivot����
�����������У�����Ԫ�رȻ�׼ֵС�İڷ��ڻ�׼ǰ�棬����Ԫ�رȻ�׼ֵ��İ��ڻ�׼�ĺ���
����ͬ�������Ե���һ�ߣ�������������˳�֮�󣬸û�׼�ʹ������е��м�λ�á�
�����Ϊ������partition��������
�ݹ�أ�recursive����С�ڻ�׼ֵԪ�ص������кʹ��ڻ�׼ֵԪ�ص�����������

�㷨α����
	function quicksort(q)
		var list less, pivotList, greater
		if length(q) �� 1 {
			return q
		} else {
			select a pivot value pivot from q
			for each x in q except the pivot element
				if x < pivot then add x to less
				if x �� pivot then add x to greater
			add pivot to pivotList
			return concatenate(quicksort(less), pivotList, quicksort(greater))
		}

ԭ��(in-place)�����İ汾
����򵥰汾��ȱ���ǣ�����Ҫ��(n)�Ķ���洢�ռ䣬Ҳ�͸��鲢����һ�����á�
������Ҫ�Ĵ洢���ռ����ã���ʵ���ϵ�ʵ�֣�Ҳ�Ἣ��Ӱ���ٶȺ͸��ٻ�������ܡ�
��һ���Ƚϸ���ʹ��ԭ�أ�in-place�������㷨�İ汾�����ںõĻ�׼ѡ���ϣ�
ƽ�����ԴﵽO(log n)�ռ��ʹ�ø��Ӷȡ�

	function partition(a, left, right, pivotIndex)
		pivotValue := a[pivotIndex]
		swap(a[pivotIndex], a[right]) // �� pivot �Ƶ��Yβ
		storeIndex := left
		for i from left to right-1
			if a[i] < pivotValue
				swap(a[storeIndex], a[i])
				storeIndex := storeIndex + 1
		swap(a[right], a[storeIndex]) // �� pivot �Ƶ�������ĵط�
		return storeIndex	
	
����ԭ�ط����㷨���������˱�ʾΪ "��ߣ�left��" �� "�ұߣ�right��" �Ĵ��в��ݣ�
�����ƶ�С��a[pivotIndex]������Ԫ�ص��Ӵ��еĿ�ͷ���������д��ڻ���ڵ�Ԫ�ؽ������Ǻ��档
�����������ҲΪ��׼Ԫ����Ѱ���ڷŵ�λ�ã�Ҳ�������ش���ֵ��
����ʱ�ذѻ�׼Ԫ���Ƶ��Ӵ��еĽ�β�������ᱻǰ����ʽӰ�쵽��
�����㷨ֻʹ�ý������������������ԭ�ȵ�����ӵ��һ����Ԫ�ء�
Ҫע����ǣ�һ��Ԫ���ڵ����������λ��ǰ�����ܻᱻ�����ܶ�Ρ�
һ������������������㷨��Ҫд�������б���ͺ����ף�
	
	
	
*/


/*

35976481234
      |
ѡ��һ����׼Ԫ�أ���8
Ȼ���û�8�����һλ��
35976441238
      |
��ʼforѭ������0�����һλǰ
���С��pivotValue����ô��storeIndex�滻������storeIndex++

35796441238
   |
storeIndex:2

35697441238
    |
storeIndex:3

*/

int middle(int *a, int x, int y, int z)
{
	if (a[x] > a[y]) {
		if (a[y] > a[z])
			return y;
		else
			return z;
	} else {
		if (a[x] > a[z])
			return z;
		else
			return x;
	}
}

int select_pivot(int *a, int left, int right)
{
	int m = (left + right) / 2;
	//return middle(a, left, right, m);
	return left;
}

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int *a, int left, int right, int pivotIndex)
{
	int i;
	int pivotValue = a[pivotIndex];
	int storeIndex = left;

	swap(a + pivotIndex, a + right);

	for (i = left; i < right - 1; i++) {
		if (a[i] < pivotValue) {
			swap(a + i, a + storeIndex);
			++storeIndex;
		}
	}
	swap(a + right, a + storeIndex);
	return storeIndex;
}

void quick_sort(int *a, int left, int right)
{
	int pivotIndex;
	int storeIndex;

	if (left < right) {
		pivotIndex = select_pivot(a, left, right);
		storeIndex = partition(a, left, right, pivotIndex);
		quick_sort(a, left, storeIndex - 1);
		quick_sort(a, storeIndex + 1, right);
	}
}

int main()
{
	int i;
	int asize = 5;
	int a[] = {1, 5, 9, 7, 3};
	quick_sort(a, 0, asize - 1);
	for (i = 0; i < asize; i++)
		printf("%d ", a[i]);
	return 0;
}