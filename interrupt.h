/*
 * IncFile1.h
 *
 * Created: 11/01/2015 08:05:57 م
 *  Author: MiKeL
 */ 

/*
	Function Name : External interrupt initialization.
	Description	  : Initialize any external interrupt (INT0,INT1,INT2).
	Arguments	  :		intrrpt_no >> Interrupt number (0, 1, 2).
						trigger_type >> (0,1,2,3)
										 0 = Low-Level triggered. { N.B: INT2 doesn't support this mode }
										 1 = Edge triggered ( Falling & Rising ). { N.B: INT2 doesn't support this mode }
										 2 = Falling Edge Triggered.
										 3 = Rising edge Triggered.
										  
	Default		  : INT0 with Rising-edge trigger type.
*/
extern void void_init_extern_intrrpt(unsigned char intrrpt_no, unsigned char trigger_type);