using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace Schur
{
    class Program
    {
        static void Main()
        {
            Console.WriteLine("输入舒尔数需求");
            try
            {
                int i = Convert.ToInt32(Console.ReadLine());
                if (i == 1)
                {
                    OrderList orderList = new OrderList(1);
                    orderList.AddIn(1, 0);
                    Console.WriteLine("寻得最终结果：最大数组：");
                    ShowResult(orderList);
                    Console.WriteLine("可能性总数:1");
                    Console.WriteLine("结果总数:1");
                    Console.WriteLine("平均结果:1");
                    Console.WriteLine("最大值:1");
                }
                else
                {
                    SchurGet(i);
                }
            }
            catch
            {
                Console.WriteLine("数据项不符合要求");
            }
            Console.ReadKey();
        }
        public static void ShowResult(OrderList list)
        {
            for(int i = 0; i < list.listCount; i++)
            {
                Console.Write("序列" + i + ":");
                foreach(int j in list.countList[i])
                {
                    Console.Write(j + " ");
                }
                Console.Write("\n");
            }
        }
        static public void SchurGet(int n)
        {
            BigInteger total = 0;

            BigInteger wayCount = 0;
            OrderList orderList = new OrderList(n);
            List<OrderList> stateList = new List<OrderList>();
            List<List<int>> wayState = new List<List<int>>();
            int step = 0;
            orderList.AddIn(1, 0);
            orderList.AddIn(2, 1);
            orderList.nextCount = 3;
            bool isEnd;
            OrderList maxList = new OrderList(n);
            while (true)
            {
                
                if (stateList.Count <= step)
                {
                    stateList.Add(orderList.Copy());
                }
                else
                {
                    stateList[step] = orderList.Copy();
                }
                

                isEnd = true;
                for(int i = 0; i < n; i++)
                {
                    if(!orderList.CheckFrom(orderList.nextCount, i))
                    {
                        if (wayState.Count <= step)
                        {
                            wayState.Add(new List<int>(3));
                        }
                        wayState[step].Add(i);
                        isEnd = false;
                    }

                }
                if (isEnd)
                {

                    //Console.WriteLine("_______________________________");
                    //Console.WriteLine("结果:");
                    //ShowResult(orderList);
                    //Console.WriteLine("_______________________________");
                   
                    total += orderList.nextCount;
                    
                    
                        
                    
                    wayCount += 1;
                    if (orderList.nextCount > maxList.nextCount)
                    {
                        Console.WriteLine("寻得最大数组，长度为:" + (step + 2));
                        maxList = orderList.Copy();
                    }
                    /*for (int i = 0; i < stateList.Count; i++)
                    {
                        Console.WriteLine("第" + i + "阶:");
                        ShowResult(stateList[i]);
                    }*/
                    
                    step -= 1;
                    
                    //回手判定
                    orderList = stateList[step];
                    stateList[step] = orderList.Copy();
                    //Console.WriteLine("_______________________________");
                    //Console.WriteLine("重读回手:");
                    //ShowResult(orderList);
                    //Console.WriteLine("_______________________________");


                    wayState[step].RemoveAt(0);
                    bool isAll = false;
                    while (!isAll)
                    {
                        if (wayState.Count == 0)
                        {
                            //Console.WriteLine("寻得最终结果：最大数组：");
                            //ShowResult(maxList);
                            return;
                        }
                        if (wayState[step].Count == 0)
                        {
                            //Console.WriteLine("当前经过的可能性:" + wayCount);
                            //Console.WriteLine("当前结果总数:" + total);
                            //Console.WriteLine("总数溢出次数:" + outCount);
                            //Console.WriteLine("当前平均值:" + total / wayCount);
                            //Console.WriteLine("清空一阶");
                            //wayState.RemoveAt(step);
                            step -= 1;
                            if (step < 0)
                            {
                                Console.WriteLine("寻得最终结果：最大数组：");
                                ShowResult(maxList);
                                Console.WriteLine("可能性总数:" + wayCount);
                                Console.WriteLine("结果总数:" + total);
                                Console.WriteLine("平均结果:" + total / wayCount);
                                Console.WriteLine("最大值:"+maxList.nextCount);
                                return;
                            }
                            wayState[step].RemoveAt(0);
                            
                            continue;
                        }
                        isAll = true;
                    }
                    orderList = stateList[step];
                    stateList[step] = orderList.Copy();





                }
                
                orderList.AddIn(orderList.nextCount, wayState[step][0]);
                step += 1;
                orderList.nextCount += 1;
                

            }
        }
    }

    public struct OrderList
    {
        public List<List<int>> countList;
        public List<List<int>> checkList;
        public int listCount;
        public int nextCount;
        public OrderList(int n)
        {
            countList = new List<List<int>>();
            checkList = new List<List<int>>();
            nextCount = 3;
            listCount = n;
            for(int i = 0; i < listCount; i++)
            {
                countList.Add(new List<int>());
                checkList.Add(new List<int>());
            }
        }
        public void AddIn(int count,int listIndex)
        {
            if (countList.Count <= listIndex)
            {
                Console.WriteLine("Error ListIndex of AddIn :"+listIndex);
                return;
            }
            if (countList[listIndex].Contains(count))
            {
                Console.WriteLine("Error Count of AddIn:"+count+"for"+listIndex);
                return;
            }
            countList[listIndex].Add(count);
            //Console.WriteLine("SuccessfulAddIn:" + count + "for" + listIndex);
            //Console.WriteLine("数列" + listIndex + "加入数:"+count);
            foreach (int i in countList[listIndex])
            {
                if (!checkList[listIndex].Contains(i + count))
                {
                    checkList[listIndex].Add(i + count);
                    //Console.WriteLine("数列" + listIndex + "加入识别数:" +( i + count));
                }
            }
        }
        public bool CheckFrom(int count,int listIndex)
        {
            if (checkList.Count <= listIndex)
            {
                Console.WriteLine("Error ListIndex of CheckFrom :" + listIndex);
                return false;
            }
            if (checkList[listIndex].Contains(count))
            {
                return true;
            }
            return false;
        }
        public OrderList Copy()
        {
            OrderList ocopy = new OrderList(this.listCount); // 初始化新实例，传递listCount
            for (int i = 0; i < this.listCount; i++)
            {
                ocopy.countList[i] = new List<int>(this.countList[i]); // 深度复制countList
                ocopy.checkList[i] = new List<int>(this.checkList[i]); // 深度复制checkList
            }
            ocopy.nextCount = this.nextCount;
            return ocopy;
        }
    }
}