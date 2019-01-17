/*	9-12-12-15-15.53.c -- 第九章第十二题	*/
/*	Pseudocode	*/

FlowType FindMaxFlow (const Tree T, FlowType IncomingFlow) ;

FlowType FindMaxFlow (const Tree T, FlowType IncomingFlow)
{
	FlowType ChildFlow, TotalFlow ;

	if (IsLeaf (T))
		return IncomingFlow ;
	else
	{
		TotalFlow = 0 ;
		for each child Ti of T
		{
			/*	It is important to make sure that IncomingFlow is the smallest flow between IncomingFlow and ci	*/
			ChildFlow = FindMaxFlow (Ti, min (IncomingFlow, ci)) ;
			TotalFlow += ChildFlow ;
			IncomingFlow -= ChildFlow ;
		}
		return TotalFlow ;
	}
}