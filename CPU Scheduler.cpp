#include <bits/stdc++.h>
using namespace std;

struct Process {
	int p; // Process ID
	int bt; // Burst Time
	int at; // Arrival Time
	int rt; // Remaining Burst Time
	int wt; // Waiting Time
	int tat; //Turn Around Time
}p[20], temp, org[20];

struct comp{
	char algo[20];
	float avg_wt;
	float avg_tat;
}algo[20];


void menu();
void input();
void assign();
void comparator();

void fcfs(int);
void sjf(int);
void rr(int);
void srtf(int);
void irr(int);
void irr_mean_tq(int);
void irr_min_tq(int);
void irrsjf(int);
void irrsjfdtq(int);


int n;

int main()
{
	cout<<"###############################  WELCOME TO OS PROJECT  ###############################\n\n";
	menu();
	return 0;
}


void menu()
{
	int ch;
	printf("\n\nTable\n\n1.New Input\n2.FCFS Algorithm\n3.RR Algorithm\n4.IRR Algorithm\n5.IRR_MEAN_TQ  Algorithm\n6.IRR_MIN_TQ  Algorithm\n7.IRR_SJF  Algorithm\n8.IRR_SJF_DTQ  Algorithm\n9.Compare All\n10.Exit");
	printf("\n\nEnter your choice from the above table : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:input();break;
			case 2:fcfs(1);break;
			case 3:rr(1);break;
			case 4:irr(1);break;
			case 5:irr_mean_tq(1);break;
			case 6:irr_min_tq(1);break;
			case 7:irrsjf(1);break;
			case 8:irrsjfdtq(1);break;
			case 9:comparator();break;
			case 10:exit(0);break;
			default: printf("\n\nPlease enter choice from 1 to 10 only\n");menu();
		}
}


void input()
{
	cout<<"\nEnter Number of processes : ";
	cin>>n;
		
	cout<<"\n\nEnter the Burst Time of the Processes : \n"; 
	for(int i=0;i<n;i++)
	{
		cout<<"Process "<<i+1<<" : ";
		cin>>org[i].bt;
		org[i].rt=org[i].bt;
	}
	
	cout<<"\n\nEnter the Arrival Time of the Processes : \n";
	
	for(int i=0; i<n; i++)
	{
		cout<<"Process "<<i+1<<" : ";
		cin>>org[i].at;
		org[i].p=i+1;
	}
	menu();
}

sort_at()
{
	for(int i=0; i<n-1; i++)
	{
		for(int j=0; j<n-i-1; j++)
		{
			if(p[j].at>p[j+1].at)
			{
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
}

void assign()
{
	for(int i=0; i<n; i++)
		p[i]=org[i];
}

void fcfs(int menu_flag)
{
	cout<<"\n\n\n#############  First Come First Serve  #############\n\n\n";
	assign();
	sort_at();
	int sum=0, tot_tat=0, tot_wt=0;
	for(int i=0; i<n; i++)
	{
		p[i].wt=sum-p[i].at;
		if(p[i].wt<0)
			p[i].wt=0;
		p[i].tat=p[i].bt+p[i].wt;
		sum+=p[i].bt;
		tot_tat+=p[i].tat;
		tot_wt+=p[i].wt;
	}
	cout<<"Process    Burst Time    Arrival Time    Waiting Time    Turn Around Time\n";
	for(int i=0; i<n; i++)
		cout<<"   "<<p[i].p<<"\t\t"<<p[i].bt<<"\t\t"<<p[i].at<<"\t\t"<<p[i].wt<<"\t\t"<<p[i].tat<<"\n";
	cout<<"\nAverage Waiting Time = "<<(float)tot_wt/n;
	cout<<"\nAverage Turn Around Time = "<<(float)tot_tat/n<<"\n";
	strcpy(algo[0].algo,"fcfs");
	algo[0].avg_tat=(float)tot_tat/n;
	algo[0].avg_wt=(float)tot_wt/n;
	if(menu_flag)
		menu();
}

void srtf(int menu_flag)
{
	cout<<"\n\n\n#############  Shortest Remaining Time First  #############\n\n\n";
	assign(); 
	int tot_wt=0, tot_tat=0;  
  
    int complete = 0, t = 0, minm = INT_MAX; 
    int shortest = 0, finish_time; 
    bool check = false; 
  
    // Process until all processes gets completed 
    while (complete != n) { 
  
        // Find process with minimum 
        // remaining time among the 
        // processes that arrives till the 
        // current time` 
        for (int j = 0; j < n; j++) { 
            if ((p[j].at <= t) && (p[j].rt < minm) && p[j].rt > 0) 
			{ 
                minm = p[j].rt; 
                shortest = j; 
                check = true; 
            } 
        } 
  
        if (check == false) 
		{ 
            t++; 
            continue; 
        } 
  
        // Reduce remaining time by one 
        p[shortest].rt--; 
  
        // Update minimum 
        minm = p[shortest].rt; 
        if (minm == 0) 
            minm = INT_MAX; 
  
        // If a process gets completely 
        // executed 
        if (p[shortest].rt == 0) { 
  
            // Increment complete 
            complete++; 
  
            // Find finish time of current 
            // process 
            finish_time = t + 1; 
  
            // Calculate waiting time 
            p[shortest].wt = finish_time - p[shortest].bt - p[shortest].at; 
  			
            if (p[shortest].wt < 0) 
                p[shortest].wt = 0; 
        } 
        // Increment time 
        t++; 
    }
	
	for(int i=0; i<n; i++)
	{
		p[i].tat=p[i].bt+p[i].wt;
		tot_wt+=p[i].wt;
		tot_tat+=p[i].tat;
	}
	cout<<"Process    Burst Time    Arrival Time    Waiting Time    Turn Around Time\n";
	for(int i=0; i<n; i++)
		cout<<"   "<<p[i].p<<"\t\t"<<p[i].bt<<"\t\t"<<p[i].at<<"\t\t"<<p[i].wt<<"\t\t"<<p[i].tat<<"\n";
	cout<<"\nAverage Waiting Time = "<<(float)tot_wt/n;
	cout<<"\nAverage Turn Around Time = "<<(float)tot_tat/n<<"\n"; 
	strcpy(algo[8].algo,"srtf");
	algo[8].avg_tat=(float)tot_tat/n;
	algo[8].avg_wt=(float)tot_wt/n;
	if(menu_flag)
		menu();
}

void sjf(int menu_flag)
{
	cout<<"\n\n\n#############  Shortest Job First  #############\n\n\n";
	assign();
	sort_at();
	int tot_wt=0, tot_tat=0,sum=0, btime=0, k=1, min;
	for(int j=0;j<n;j++)
	{
		btime=btime+p[j].bt;
		min=p[k].bt;
		for(int i=k;i<n;i++)
		{
			if (btime>=p[i].at && p[i].bt<min)
			{
				temp=p[k];
				p[k]=p[i];
				p[i]=temp;
			}
		}
		k++;
	}
	
	p[0].wt=0;
	for(int i=1;i<n;i++)
	{
		sum+=p[i-1].bt;
		p[i].wt=sum-p[i].at;
		tot_wt+=p[i].wt;
		p[i].tat=p[i].bt+p[i].wt;
		tot_tat+=p[i].tat;
	}
	cout<<"Process    Burst Time    Arrival Time    Waiting Time    Turn Around Time\n";
	for(int i=0; i<n; i++)
		cout<<"   "<<p[i].p<<"\t\t"<<p[i].bt<<"\t\t"<<p[i].at<<"\t\t"<<p[i].wt<<"\t\t"<<p[i].tat<<"\n";
	cout<<"\nAverage Waiting Time = "<<(float)tot_wt/n;
	cout<<"\nAverage Turn Around Time = "<<(float)tot_tat/n<<"\n"; 
	strcpy(algo[7].algo,"sjf");
	algo[7].avg_tat=(float)tot_tat/n;
	algo[7].avg_wt=(float)tot_wt/n;
	if(menu_flag)
		menu();
}
 
void rr(int menu_flag) 
{ 
	cout<<"\n\n\n#############  Round Robin  #############\n\n\n";
	assign();
  int remain=n, time_quantum, tot_wt=0, tot_tat=0, flag=0; 
  sort_at();
  cout<<"\nEnter Time Quantum : "; 
  cin>>time_quantum;  
  for(int i=0,time=0; remain!=0;) 
  { 
    if(p[i].rt<=time_quantum && p[i].rt>0) 
    { 
      time+=p[i].rt; 
      p[i].rt=0; 
      flag=1; 
    } 
    else if(p[i].rt>0) 
    { 
      p[i].rt-=time_quantum; 
      time+=time_quantum; 
    } 
    if(p[i].rt==0 && flag==1) 
    { 
      remain--; 
      p[i].wt=time-p[i].at-p[i].bt;
	  p[i].tat=time-p[i].at;
      tot_wt+=p[i].wt; 
      tot_tat+=p[i].tat; 
      flag=0; 
    } 
    if(i==n-1) 
      i=0; 
    else if(p[i+1].at<=time) 
      i++; 
    else 
      i=0; 
  } 
  cout<<"Process    Burst Time    Arrival Time    Waiting Time    Turn Around Time\n";
	for(int i=0; i<n; i++)
		cout<<"   "<<p[i].p<<"\t\t"<<p[i].bt<<"\t\t"<<p[i].at<<"\t\t"<<p[i].wt<<"\t\t"<<p[i].tat<<"\n";
	cout<<"\nAverage Waiting Time = "<<(float)tot_wt/n;
	cout<<"\nAverage Turn Around Time = "<<(float)tot_tat/n<<"\n"; 
	strcpy(algo[1].algo,"rr");
	algo[1].avg_tat=(float)tot_tat/n;
	algo[1].avg_wt=(float)tot_wt/n;
	if(menu_flag)
		menu();
}


void irr(int menu_flag) 
{ 
	cout<<"\n\n#############  Improved Round Robin  #############\n\n";
	assign();
  int remain=n, rt[n], time_quantum, tot_wt=0, tot_tat=0, flag=0; 
  sort_at();
  for(int i=0; i<n; i++)  
    rt[p[i].p-1]=p[p[i].p-1].bt;
  cout<<"\nEnter Time Quantum : "; 
  cin>>time_quantum;  
  for(int i=0,time=0; remain!=0;) 
  { 
    if(p[i].rt<=time_quantum && p[i].rt>0) 
    { 
      time+=p[i].rt; 
      p[i].rt=0; 
      flag=1; 
    } 
    else if(p[i].rt>time_quantum && p[i].rt>0 && time_quantum*2-p[i].rt>=0)
    { 
      time+=p[i].rt; 
      p[i].rt=0; 
      flag=1; 
    } 
    else if(p[i].rt>0) 
    { 
      p[i].rt-=time_quantum; 
      time+=time_quantum; 
    } 
    if(p[i].rt==0 && flag==1) 
    { 
      remain--; 
      p[i].wt=time-p[i].at-p[i].bt;
	  p[i].tat=time-p[i].at;
      tot_wt+=p[i].wt; 
      tot_tat+=p[i].tat; 
      flag=0; 
    } 
    if(i==n-1) 
      i=0; 
    else if(p[i+1].at<=time) 
      i++; 
    else 
      i=0; 
  } 
  cout<<"Process    Burst Time    Arrival Time    Waiting Time    Turn Around Time\n";
	for(int i=0; i<n; i++)
		cout<<"   "<<p[i].p<<"\t\t"<<p[i].bt<<"\t\t"<<p[i].at<<"\t\t"<<p[i].wt<<"\t\t"<<p[i].tat<<"\n";
	cout<<"\nAverage Waiting Time = "<<(float)tot_wt/n;
	cout<<"\nAverage Turn Around Time = "<<(float)tot_tat/n<<"\n"; 
	strcpy(algo[2].algo,"irr");
	algo[2].avg_tat=(float)tot_tat/n;
	algo[2].avg_wt=(float)tot_wt/n;
	if(menu_flag)
		menu();
}

void irr_mean_tq(int menu_flag) 
{ 
	cout<<"\n\n#############  Improved Roud Robin with Mean Quantum Time  #############\n\n";
	assign();
  int remain=n, rt[n], time_quantum, tot_wt=0, tot_tat=0, flag=0, mean=0; 
  sort_at();
  for(int i=0; i<n; i++)  
    rt[p[i].p-1]=p[p[i].p-1].bt;  
  for(int i=0,time=0; remain!=0;) 
  { 
	mean=0;
  	for(int j=0; j<n; j++)
	  	mean+=p[j].rt;
	time_quantum = (mean/remain + 1) / 2;	
    if(p[i].rt<=time_quantum && p[i].rt>0) 
    { 
      time+=p[i].rt; 
      p[i].rt=0; 
      flag=1; 
    } 
    else if(p[i].rt>time_quantum && p[i].rt>0 && time_quantum*2-p[i].rt>=0)
    { 
      time+=p[i].rt; 
      p[i].rt=0; 
      flag=1; 
    }
    else if(p[i].rt>0) 
    { 
      p[i].rt-=time_quantum; 
      time+=time_quantum; 
    } 
    if(p[i].rt==0 && flag==1) 
    { 
      remain--; 
      p[i].wt=time-p[i].at-p[i].bt;
	  p[i].tat=time-p[i].at;
      tot_wt+=p[i].wt; 
      tot_tat+=p[i].tat; 
      flag=0; 
    } 
    if(i==n-1) 
      i=0; 
    else if(p[i+1].at<=time) 
      i++; 
    else 
      i=0; 
  } 
  cout<<"Process    Burst Time    Arrival Time    Waiting Time    Turn Around Time\n";
	for(int i=0; i<n; i++)
		cout<<"   "<<p[i].p<<"\t\t"<<p[i].bt<<"\t\t"<<p[i].at<<"\t\t"<<p[i].wt<<"\t\t"<<p[i].tat<<"\n";
	cout<<"\nAverage Waiting Time = "<<(float)tot_wt/n;
	cout<<"\nAverage Turn Around Time = "<<(float)tot_tat/n<<"\n"; 
	strcpy(algo[3].algo,"irr_mean_tq");
	algo[3].avg_tat=(float)tot_tat/n;
	algo[3].avg_wt=(float)tot_wt/n;
	if(menu_flag)
		menu();

}

void irr_min_tq(int menu_flag) 
{ 
	cout<<"\n\n#############  Improved ROund Robin with Min Quantum Time  #############\n\n";
	assign();
  int remain=n, rt[n], time_quantum, tot_wt=0, tot_tat=0, flag=0, mintq=1000; 
  sort_at();
  for(int i=0; i<n; i++)  
    rt[p[i].p-1]=p[p[i].p-1].bt;  
  for(int i=0,time=0; remain!=0;) 
  { 
  	mintq=1000;
  	for(int j=0; j<n; j++)
	  	if(mintq>p[j].rt and p[j].rt!=0)
	  		mintq=p[j].rt;
	time_quantum = mintq;	
    if(p[i].rt<=time_quantum && p[i].rt>0) 
    { 
      time+=p[i].rt; 
      p[i].rt=0; 
      flag=1; 
    } 
    else if(p[i].rt>time_quantum && p[i].rt>0 && time_quantum*2-p[i].rt>=0)
    { 
      time+=p[i].rt; 
      p[i].rt=0; 
      flag=1; 
    }
    else if(p[i].rt>0) 
    { 
      p[i].rt-=time_quantum; 
      time+=time_quantum; 
    } 
    if(p[i].rt==0 && flag==1) 
    { 
      remain--; 
      p[i].wt=time-p[i].at-p[i].bt;
	  p[i].tat=time-p[i].at;
      tot_wt+=p[i].wt; 
      tot_tat+=p[i].tat; 
      flag=0; 
    } 
    if(i==n-1) 
      i=0; 
    else if(p[i+1].at<=time) 
      i++; 
    else 
      i=0; 
  } 
  cout<<"Process    Burst Time    Arrival Time    Waiting Time    Turn Around Time\n";
	for(int i=0; i<n; i++)
		cout<<"   "<<p[i].p<<"\t\t"<<p[i].bt<<"\t\t"<<p[i].at<<"\t\t"<<p[i].wt<<"\t\t"<<p[i].tat<<"\n";
	cout<<"\nAverage Waiting Time = "<<(float)tot_wt/n;
	cout<<"\nAverage Turn Around Time = "<<(float)tot_tat/n<<"\n"; 
	strcpy(algo[4].algo,"irr_min_tq");
	algo[4].avg_tat=(float)tot_tat/n;
	algo[4].avg_wt=(float)tot_wt/n;
	if(menu_flag)
		menu();
}

void irrsjf(int menu_flag)
{
	cout<<"\n\n#############  Imporved Roubd Robin Shortest Job First  #############\n\n";
    int time_quantum,tot_tat=0, tot_wt=0;
    int remain=n;
    int time=0; 
	int old_mean=0;
    
    cout<<"\nEnter Time Quantum : "; 
	cin>>time_quantum;
    
    for(int i=0; i<n; i++)
		p[i].rt=p[i].bt;
	while(remain>0)
	{	
		//sorting in ascending order
		for(int i=0;i<n;i++)
			for(int j=0;j<n-i-1;j++)
				if(p[j].rt>p[j+1].rt)
				{
					temp=p[j+1];
					p[j+1]=p[j];
					p[j]=temp;
				}	
		for(int i=0;i<n;i++) //loop main
		{
			if(p[i].at<=time && p[i].rt!=0)
    		{
        		if(p[i].rt<time_quantum && p[i].rt!=0)
    			{
			        time+=p[i].rt;
			        p[i].rt=0;
    			}
        		else if(p[i].rt>time_quantum && p[i].rt>0 && time_quantum*2-p[i].rt>=0)
			    { 
			      time+=p[i].rt; 
			      p[i].rt=0;  
			    }
				else
   		 		{
			        time+=time_quantum;
			        p[i].rt-=time_quantum;
    			}
        		
				if(p[i].rt==0)
    			{
			        p[i].wt=time-p[i].bt-p[i].at;
			        p[i].tat=time-p[i].at;
					remain--;
    			}
    		}
		}
	}
	for(int i=0; i<n; i++)
	{
		tot_wt += p[i].wt;
		tot_tat += p[i].tat; 
	}
	cout<<"Process    Burst Time    Arrival Time    Waiting Time    Turn Around Time\n";
	for(int i=0; i<n; i++)
		cout<<"   "<<p[i].p<<"\t\t"<<p[i].bt<<"\t\t"<<p[i].at<<"\t\t"<<p[i].wt<<"\t\t"<<p[i].tat<<"\n";
	cout<<"\nAverage Waiting Time = "<<(float)tot_wt/n;
	cout<<"\nAverage Turn Around Time = "<<(float)tot_tat/n<<"\n"; 
	strcpy(algo[5].algo,"irr_sjf");
	algo[5].avg_tat=(float)tot_tat/n;
	algo[5].avg_wt=(float)tot_wt/n;
	if(menu_flag)
		menu();
}



void irrsjfdtq(int menu_flag)
{
	cout<<"\n\n#############  Improved Round Robin Shortest Job First with Dynamic Quantum Time  #############\n\n";
    int time_quantum,tot_tat=0, tot_wt=0;
    int remain=n;
    int time=0;
    int max_bt;
    int sum_bt,prq;  // prq = process in ready queue
	int old_mean=0;
    
    for(int i=0; i<n; i++)
    {	
		p[i].rt=p[i].bt;
		old_mean+=p[i].bt;
	}
	old_mean/=n;
	while(remain>0)
	{
		//sorting in ascending order
		for(int i=0;i<n;i++)
			for(int j=0;j<n-i-1;j++)
				if(p[j].rt>p[j+1].rt)
				{
					temp=p[j+1];
					p[j+1]=p[j];
					p[j]=temp;
				}	
		for(int i=0;i<n;i++) //loop main
		{
			prq=0;  
        	max_bt=0;
        	sum_bt=0;
    		for(int j=0;j<n;j++)
	    	{
				if(p[j].at<=time && p[j].rt!=0)
				{
	        		prq++;
	        		if(p[j].rt>max_bt)
	            		max_bt=p[j].rt;
	        		sum_bt+=p[j].rt;
	    		}
	    	}
	    	
			if(prq==0 ||  (sum_bt/prq) == 0)
	    		time_quantum = old_mean;
	    	else
	    	{
				time_quantum=sum_bt/prq;
				old_mean = time_quantum;
			}
			if(p[i].at<=time && p[i].rt!=0)
    		{
        		if(p[i].rt<time_quantum && p[i].rt!=0)
    			{
			        time+=p[i].rt;
			        p[i].rt=0;
    			}
        		else if(p[i].rt>time_quantum && p[i].rt>0 && time_quantum*2-p[i].rt>=0)
			    { 
			      time+=p[i].rt; 
			      p[i].rt=0;  
			    }
				else
   		 		{
			        time+=time_quantum;
			        p[i].rt-=time_quantum;
    			}
        		
				if(p[i].rt==0)
    			{
			        p[i].wt=time-p[i].bt-p[i].at;
			        p[i].tat=time-p[i].at;
					remain--;
    			}
    		}
		}
	}
	for(int i=0; i<n; i++)
	{
		tot_wt += p[i].wt;
		tot_tat += p[i].tat; 
	}
	cout<<"Process    Burst Time    Arrival Time    Waiting Time    Turn Around Time\n";
	for(int i=0; i<n; i++)
		cout<<"   "<<p[i].p<<"\t\t"<<p[i].bt<<"\t\t"<<p[i].at<<"\t\t"<<p[i].wt<<"\t\t"<<p[i].tat<<"\n";
	cout<<"\nAverage Waiting Time = "<<(float)tot_wt/n;
	cout<<"\nAverage Turn Around Time = "<<(float)tot_tat/n<<"\n"; 
	strcpy(algo[6].algo,"irr_sjf_dtq");
	algo[6].avg_tat=(float)tot_tat/n;
	algo[6].avg_wt=(float)tot_wt/n;
	if(menu_flag)
		menu();
}


void comparator()
{
	fcfs(0);
	sjf(0);
	rr(0);
	irr(0);
	irr_mean_tq(0);
	irr_min_tq(0);
	irrsjf(0);
	irrsjfdtq(0);
	srtf(0);
	cout<<"\n\n#############  Comparing All  #############\n\n";
	cout<<"\n\n Algorithm\t\tAVG_WT\t\tAVG_TAT\n\n";
	for(int i=0; i<7; i++)
		if(strlen(algo[i].algo)>4)
			cout<<"   "<<algo[i].algo<<"\t\t"<<algo[i].avg_wt<<"\t\t"<<algo[i].avg_tat<<"\n";
		else	
			cout<<"   "<<algo[i].algo<<"\t\t\t"<<algo[i].avg_wt<<"\t\t"<<algo[i].avg_tat<<"\n";
	menu();
}


