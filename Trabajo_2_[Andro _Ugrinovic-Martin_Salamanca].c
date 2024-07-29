//Andro Jaromir Uginovic Ocares, rut: 21.689.965-2
//Martin Antonio Salamanca Rubilar, rut: 22.019.952-5

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//______Funciones promedios_______//
void ingresar_prom(float vecP[], int a);
void ingresar_random_prom(float vecP[], int a);
void mostrar_prom(float vecP[], int a);
float mostrar_prom_mayor(float vecP[], int a);
int mostrar_edad_mayor_all(int matE[], int b);
void mostrar_prom_3(float vecP[], int a);
float promedio_general(float vecP[], int a);

//______Funciones Edades_____//
void ingresar_edad(int vecE[], int a);
void ingresar_random_edad(int vecE[], int a);
void mostrar_edad(int vecE[], int a);
int mostrar_edad_mayor(int vecE[], int a);
int mostrar_edad_menor(int vecE[], int a);
int edad_repetida(int vecE[], int a);

//______Validaciones______//
int validar_alumnos();
int validar_opcion();
int validar_main_op();

//_____Funciones Menu Void_____//
void menu1();
void menu2();
void menu_cursos();

//_______Programa Principal________//
int main(){
	
	srand(time (NULL));
	
	int op_main, op_second; //variables opciones principales y secundarias
	int op_ingP, op_ingP2, op_mostP; //variables opciones ingresar y mostrar promedio
	int op_ingE, op_ingE2, op_mostE; //variables opciones ingresar y mostrar edad
	int op_edad_MyM, op_edad_MyM2;//variables mostrar edad mayor y menor de cada curso a eleccion
	int op_prom_mayor, op_prom_3;//variable promedio mayor por curso
	int op_moda;//variable mostar moda de cada curso;
	int op_prom_general;//variable mostrar promedios generales de cada curso
	
	int i, n, m, k, x; //cantidades de alumnos por curso
	float mejores[4]={0,0,0,0};//Vector vacio de los promedios gnenerales
	int edades_mayores[4]={0,0,0,0};//Vector vacio de las mayores edades gnenerales
	
	printf("Cuantos alumnos hay en primero medio? \n");
	n=validar_alumnos();
	printf("Cuantos alumnos hay en segundo medio? \n");
	m=validar_alumnos();
	printf("Cuantos alumnos hay en tercero medio? \n");
	k=validar_alumnos();
	printf("Cuantos alumnos hay en cuarto medio? \n");
	x=validar_alumnos();
	
	float grad1P[n],grad2P[m],grad3P[k],grad4P[x]; //vectores de promedios de alumnos
	int grad1E[n],grad2E[m],grad3E[k],grad4E[x]; //vectores de edades de alumnos
	
	float grad_all_prom[4][20];//matriz de todos los promedios de los cursos
	int grad_all_edad[4][20];// matriz de todas las edades de los cursos
	
	do{
		//menu principal
		menu1();
	    op_main=validar_main_op();
		switch(op_main){
		    case 1:
		    	//Ingresar Promedios
		    	do{
		    		printf("\n[Elegir curso: ]");
					menu_cursos();
		    		op_ingP=validar_opcion();
		        	switch(op_ingP){
		    		
		        		case 1://primero medio
		        			printf("\nop1: Ingresar promedios manualmente.  op2: Ingresar promedios automaticamente. \n\n");
		        			printf("Elegir opcion:  ");
		        			scanf("%d", &op_ingP2);
		        			if(op_ingP2==1){
		        				ingresar_prom(grad1P,n);//manual
			    			}
			    			if(op_ingP2==2){
			    				ingresar_random_prom(grad1P,n);//random
			    			}
		        			break;
		        		case 2://segundo medio
		        			printf("\nop1: Ingresar promedios manualmente.  op2: Ingresar promedios automaticamente. \n\n");
		        			printf("Elegir opcion:  ");
		        			scanf("%d", &op_ingP2);
		        			if(op_ingP2==1){
		         				ingresar_prom(grad2P,m);//manual
		    				}
			    			if(op_ingP2==2){
			    				ingresar_random_prom(grad2P,m);//random
			    			}
		        			break;
		        		case 3://tercero medio
		         			printf("\nop1: Ingresar promedios manualmente.  op2: Ingresar promedios automaticamente. \n\n");
		         			printf("Elegir opcion:  ");
		        			scanf("%d", &op_ingP2);
		    	    		if(op_ingP2==1){
		    	    			ingresar_prom(grad3P,k);//manual
				    		}
				    		if(op_ingP2==2){
				     		    ingresar_random_prom(grad3P,k);//random
			    			}
		    	    		break;
		        		case 4://cuarto medio
		         			printf("\nop1: Ingresar promedios manualmente.  op2: Ingresar promedios automaticamente. \n\n");
		         			printf("Elegir opcion:  ");
		        			scanf("%d", &op_ingP2);
		        			if(op_ingP2==1){
		        				ingresar_prom(grad4P,x);//manual
			    			}
			    			if(op_ingP2==2){
				    			ingresar_random_prom(grad4P,x);//random
				    		}
		        			break;
		        		case 5:
		        			printf("\n\n Volviendo... \n\n");
		        			break;
		        		default:
		        			printf("*ERROR*");
		        			break;
			    	}
				}while(op_ingP!=5);
		    	
				break;
		    	
            case 2:
            	//Ingresar Edades
            	do{
            		printf("\n[Elegir curso: ]");
					menu_cursos();
            		op_ingE=validar_opcion();
            	    switch(op_ingE){
            	    	case 1://primero medio
            	    		printf("\nop1: Ingresar edades manualmente.  op2: Ingresar edades automaticamnete \n\n");
            	    		printf("Elegir opcion:  ");
            	    		scanf("%d", &op_ingE2);
            	    		if(op_ingE2 == 1){
            				ingresar_edad(grad1E, n);
				    		}
				     		if(op_ingE2 == 2){
				     			ingresar_random_edad(grad1E,n);
					    	}
            	    		break;
            	    	case 2://segundo medio
            	    		printf("\nop1: Ingresar edades manualmente.  op2: Ingresar edades automaticamnete \n\n");
            	    		printf("Elegir opcion:  ");
            	    		scanf("%d", &op_ingE2);
            	    		if(op_ingE2 == 1){
            	    			ingresar_edad(grad2E, m);
				    		}
				    		if(op_ingE2 == 2){
				    			ingresar_random_edad(grad2E,m);
				    		}
            	    		break;
            	    	case 3://tercero medio
                			printf("\nop1: Ingresar edades manualmente.  op2: Ingresar edades automaticamnete \n\n");
                			printf("Elegir opcion:  ");
            	    		scanf("%d", &op_ingE2);
            	    		if(op_ingE2 == 1){
            	    			ingresar_edad(grad3E, k);
				    		}
				    		if(op_ingE2 == 2){
				    			ingresar_random_edad(grad3E,k);
				    		}
            	     		break;
            	    	case 4://cuarto medio
            	    		printf("\nop1: Ingresar edades manualmente.  op2: Ingresar edades automaticamnete \n\n");
            	    		printf("Elegir opcion:  ");
            	    		scanf("%d", &op_ingE2);
            	    		if(op_ingE2 == 1){
            	    			ingresar_edad(grad4E, x);
				    		}
				    		if(op_ingE2 == 2){
				    			ingresar_random_edad(grad4E,x);
				    		}
                			break;
            		    case 5:
                			printf("\n\n Volviendo... \n\n");
            	    		break;
                		default:
                 			printf("*ERROR*");
                			break;
            		
	    			}
				}while(op_ingE!=5);
            	
            	break;
            	
		    case 3:
		    	//Mostrar Promedios
		    	do{
		    	    printf("\n[Elegir curso: ]");
					menu_cursos();
		    	    op_mostP=validar_opcion();
		    		switch(op_mostP){
		    			case 1:
		    			mostrar_prom(grad1P,n);
		    			break;
		    		case 2:
		    			mostrar_prom(grad2P,m);
		    			break;
		    		case 3:
		    			mostrar_prom(grad3P,k);
		    			break;
		    		case 4:
		    			mostrar_prom(grad4P,x);
		    			break;
		    		case 5:
		    			printf("\n\n Volviendo... \n\n");
		    			break;
		    		default:
		    			break;
					
				    }
				 }while(op_mostP!=5);
		    	
		    	break;
		    	
            case 4:
            	//Mostrar Edades
		    	do{
		    		printf("\n[Elegir curso: ]");
					menu_cursos();
		    		op_mostE=validar_opcion();
		    	    switch(op_mostE){
		    			case 1:
		    		  	    mostrar_edad(grad1E,n);
		    			    break;
		    		    case 2:
		    			    mostrar_edad(grad2E,m);
		    			    break;
		    		    case 3:
		    		    	mostrar_edad(grad3E,k);
		    		    	break;
		    		    case 4:
		    		    	mostrar_edad(grad4E,x);
		    		    	break;
		    		    case 5:
		    		    	printf("\n\n Volviendo... \n\n");
		    		    	break;
		    		    default:
		    		    	break;
					    }
				    }while(op_mostE!=5);
				
            	break;
            	
		    case 5:
		    	//Mostrar edad mayor o menor
		    	do{
		    		printf("\n[Elegir curso: ]");
		    		menu_cursos();
		    		op_edad_MyM=validar_opcion();
		    		switch(op_edad_MyM){
		    			case 1:
		    				printf("\nop1: Mostrar edad mayor.   op2: Mostrar edad menor. \n\n");
		    				printf("Elegir opcion:  ");
		        			scanf("%d", &op_edad_MyM2);
		        			if(op_edad_MyM2==1){
		        				printf("[%d]",mostrar_edad_mayor(grad1E, n));
							}
							if(op_edad_MyM2==2){
								printf("[%d]",mostrar_edad_menor(grad1E, n));
							}
		    				break;
		    			case 2:
		    				printf("\nop1: Mostrar edad mayor.   op2: Mostrar edad menor. \n\n");
		    				printf("Elegir opcion:  ");
		        			scanf("%d", &op_edad_MyM2);
		        			if(op_edad_MyM2==1){
		        				printf("[%d]",mostrar_edad_mayor(grad2E, m));
							}
							if(op_edad_MyM2==2){
								printf("[%d]",mostrar_edad_menor(grad2E, m));
							}
		    				break;
		    			case 3:
		    				printf("\nop1: Mostrar edad mayor.   op2: Mostrar edad menor. \n\n");
		    				printf("Elegir opcion:  ");
		        			scanf("%d", &op_edad_MyM2);
		        			if(op_edad_MyM2==1){
		        				printf("[%d]",mostrar_edad_mayor(grad3E, k));
							}
							if(op_edad_MyM2==2){
								printf("[%d]",mostrar_edad_menor(grad3E, k));
							}
		    				break;
		    			case 4:
		    				printf("\nop1: Mostrar edad mayor.   op2: Mostrar edad menor. \n\n");
		    				printf("Elegir opcion:  ");
		        			scanf("%d", &op_edad_MyM2);
		        			if(op_edad_MyM2==1){
		        				printf("[%d]",mostrar_edad_mayor(grad4E, x));
							}
							if(op_edad_MyM2==2){
								printf("[%d]",mostrar_edad_menor(grad4E, x));
							}
		    				break;
		    			case 5:
		    				printf("\n\n Volviendo... \n\n");
		    				break;
		    			default:
		    				printf("*ERROR*");
		    				break;
					}
				}while(op_edad_MyM!=5);
		    	
				break;
				
            case 6:
            	//menu secundario
            	do{
            		menu2();
            		op_second=validar_main_op();
            		switch(op_second){
            			case 1:	
            	            //Mostrar promedio mayor de cada curso
                        	do{
                        		printf("\n[Elegir curso: ]");
            	            	menu_cursos();
            	            	op_prom_mayor=validar_opcion();
                        		switch(op_prom_mayor){
                            		case 1:
            	        	     		printf("\nEl mayor promedio es: [%.2f]\n", mostrar_prom_mayor(grad1P, n));
            	         	    		break;
            	            		case 2:
            			            	printf("\nEl mayor promedio es: [%.2f]\n", mostrar_prom_mayor(grad2P, m));
            			            	break;
            		            	case 3:
            		            		printf("\nEl mayor promedio es: [%.2f]\n", mostrar_prom_mayor(grad3P, k));
            		            		break;
            	            		case 4:
            	             			printf("\nEl mayor promedio es: [%.2f]\n", mostrar_prom_mayor(grad4P, x));
            	            			break;
            	             		case 5:
            	             			printf("\n\n Volviendo... \n\n");
            		            		break;
            	               		default:
                         				printf("*ERROR*");
            		            		break;
			            		}
		            		}while(op_prom_mayor!=5);
            	
			            	break;
				
                        case 2:
                        	//Mostrar edad mayor de todos los cursos 
                        	edades_mayores[0]=mostrar_edad_mayor(grad1E, n);
                         	edades_mayores[1]=mostrar_edad_mayor(grad2E, m);
                        	edades_mayores[2]=mostrar_edad_mayor(grad3E, k);
                           	edades_mayores[3]=mostrar_edad_mayor(grad4E, x);
                           	int mayor_edad=edades_mayores[0];
                          	for(i=0;i<4;i++){
	                        	if(edades_mayores[i]>mayor_edad){
	                           		mayor_edad=edades_mayores[i];
                        		}
                         	}
                         	for(i=0;i<4;i++){
                        		if(mayor_edad==edades_mayores[i]){
	                        		printf("\nLa mayor edad registrada se encuentra en %d* medio y es: %d anios \n\n",(i+1),mayor_edad);
                           		}
                        	}
                        	
                        	break;
            	
	                    case 3:
		                	//Mostrar las 3 mejores notas de cada curso
		                	do{
		                 		printf("\n[Elegir curso: ]");
	            				menu_cursos();
		                		op_prom_3=validar_opcion();
		                		switch(op_prom_3){
		                			case 1:
		                				mostrar_prom_3(grad1P, n);
		                  				break;
		                			case 2:
		                  				mostrar_prom_3(grad2P, m);
		                				break;
		                  			case 3:
		                 				mostrar_prom_3(grad3P, k);
		                   				break;
	             	      			case 4:
		    		            		mostrar_prom_3(grad4P, x);
		    		            		break;
		    	            		case 5:
		    	              			printf("\n\n Volviendo... \n\n");
		    	            			break;
		    	             		default:
		    	             			break;
			            		}
			            	}while(op_prom_3!=5);
		    	
		             		break;
				
                        case 4:
                         	//Mostrar moda de cada curso
                         	do{
                        		printf("\n[Elegir curso: ]");
	            				menu_cursos();
	            	    		op_moda=validar_opcion();
                         		switch(op_moda){
                         			case 1:
                         				printf("\nLa edad mas repetida es: [%d]\n", edad_repetida(grad1E, n));
                        				break;
                         			case 2:
            	             			printf("\nLa edad mas repetida es: [%d]\n", edad_repetida(grad2E, m));
                        				break;
                         			case 3:
                         				printf("\nLa edad mas repetida es: [%d]\n", edad_repetida(grad3E, k));
                         				break;
                        			case 4:
                        				printf("\nLa edad mas repetida es: [%d]\n", edad_repetida(grad4E, x));
                         				break;
                         			case 5:
                           				printf("\n\n Volviendo... \n\n");
                         				break;
                         			default:
                           				printf("*ERROR*");
                        				break;
			             		}
		            		}while(op_moda!=5);
		              		break;
				
	            	    case 5:
		             		//Mostrar promedio general por curso
		            		do{
		             			printf("\n[Elegir curso: ]");
		               			menu_cursos();
		                  		op_prom_general=validar_opcion();
	            				switch(op_prom_general){
		            			 	case 1:
		             					printf("[%.2f]", promedio_general(grad1P, n));
		             					break;
		              				case 2:
		            					printf("[%.2f]", promedio_general(grad2P, m));
				            		    break;
				              		case 3:
				              			printf("[%.2f]", promedio_general(grad3P, k));
				            			break;
			            			case 4:
			             				printf("[%.2f]", promedio_general(grad4P, x));
			            				break;
			            			case 5:
			            				printf("\n\n Volviendo... \n\n");
			             				break;
			            			default:
			            				printf("*ERROR*");
			              				break;
			            		}
			            	}while(op_prom_general!=5);
				
			             	break;
				
		             	case 6:
		               		//Mostrar curso con mejor rendimiento (mejor promedio general de entre todos los cursos) 
                           	mejores[0]=promedio_general(grad1P,n);
                         	mejores[1]=promedio_general(grad2P,m);
                        	mejores[2]=promedio_general(grad3P,k);
                           	mejores[3]=promedio_general(grad4P,x);
                           	float mejor_curso=mejores[0];
                          	for(i=0;i<4;i++){
	                        	if(mejores[i]>mejor_curso){
	                           		mejor_curso=mejores[i];
                        		}
                         	}
                         	for(i=0;i<4;i++){
                        		if(mejor_curso==mejores[i]){
	                        		printf("\nEl %d* medio, es el curso con mejor rendimiento con un promedio general de: %.2f \n\n",(i+1),mejor_curso);
                           		}
                        	}
                        	
		             		break;
		             		
		             	case 7:
		    				printf("\n\n Volviendo... \n\n");
		    				break;
		    			default:
		    				printf("*ERROR*");
		    				break;
				
					}
				}while(op_second!=7);
            	
            	break;
            	
			case 7:
		        printf("\n\n[Programa finalizado]\n");
		        printf("gracias por utilizarlo :] \n");
		        printf("Hecho por Andro Ugrinovic y Martin Salamanca \n");
		        printf("UBB ICINF 2024\n\n");
		        
				break;
					
			default:
			    break;    		    		    		    		
		}
	}while(op_main!=7);
}

//_________Funciones__________//

void menu1(){
    printf("\n\n <<QUE DESEA HACER?>> \n\n");
	printf("[op1]: Ingresar promedios.          [op2]: Ingresar edades. \n");
	printf("[op3]: Mostrar promedios .          [op4]: Mostrar edades. \n\n");
	printf("[op5]: Edad mayor o menor por curso.");
	printf("\n[op6]: [Otras opciones]\n\n");
	printf("[op7]: Fializar programa \n\n");
}
void menu2(){
	printf("\n\n[op1]: Mostrar promedio mayor  de cada curso.             [op2]: Mostrar edad mayor de entre todos cursos. \n");
	printf("[op3]: Mostrar los 3 mejores promedios de cada curso.     [op4]: Mostrar la moda de las edades de cada curso. \n");
	printf("[op5]: Mostrar promedio general de cada curso.            [op6]: Mostrar curso con mejor rendimiento. \n\n");
	printf("                                [op7]: [Volver] \n\n");
}
void menu_cursos(){
	printf("\n\n[op1]: Primero medio.  [op2]: Segundo medio. \n");
	printf("[op3]: Tercero medio.  [op4]: Cuarto medio. \n");
	printf("            [op5]: [Volver] \n\n");
}

int validar_alumnos(){
	int a;
	do{
		printf("Ingrese la cantidad n de alumnos (max:20): ");
		scanf("%d", &a);
		if(a<1 || a>20){
			printf("[Ingrese un valor valido (1-20)]\n");
		}
	}while(a<1 || a>20);
	return(a);
}
int validar_opcion(){
	int a;
	do{
		printf("Elegir opcion:  ");
		scanf("%d",&a);
		if(a<1 || a>5){
			printf("Ingrese una opcion valida (1-5)\n");
		}
	}while(a<1 || a>5);
	return(a);
}
int validar_main_op(){
	int a;
	do{
		printf("Elegir opcion:  ");
		scanf("%d",&a);
		if(a<1 || a>7){
			printf("Ingrese una opcion valida (1-7)\n");
		}
	}while(a<1 || a>7);
	return(a);
}

int mostrar_edad_mayor(int vecE[], int a){
	int i, mayor;
	mayor=vecE[0];

	for(i=0;i<a;i++){//mayor
		if(mayor<vecE[i]){
			mayor=vecE[i];
		}
	}
	return(mayor);
}
int mostrar_edad_menor(int vecE[], int a){
	int i,menor;
	menor=vecE[0];
	for(i=0;i<a;i++){//menor
		if(menor>vecE[i]){
			menor=vecE[i];
		}
	}
	return(menor);
}

float mostrar_prom_mayor(float vecP[], int a){
	int i;
	float mayor=vecP[0];
	for(i=0;i<a;i++){
		if(mayor<vecP[i]){
			mayor=vecP[i];
		}
	}
	return(mayor);
}
void mostrar_prom_3(float vecP[], int a){
	int i;
	float vec_3[3]={0,0,0};
	for(i=0;i<a;i++){
		if(vecP[i]>vec_3[0]){
			
			    vec_3[2]=vec_3[1];
				vec_3[1]=vec_3[0];
				vec_3[0]=vecP[i];
				
		}else if(vecP[i]>vec_3[1]){
			
				vec_3[2]=vec_3[1];
				vec_3[1]=vecP[i];
				
		}else if(vecP[i]>vec_3[2]){
			
			    vec_3[2]=vecP[i];
		}
    }
	for(i=0;i<3 && i<a;i++){
		printf("\n%d* puesto con[%.2f]\n", (i+1),vec_3[i]);
	}
}

int edad_repetida(int vecE[], int a){
	int i,j,cont=0,max_cont=0,moda=0;
	for(i=0;i<a;i++){
		cont=0;
		for(j=0;j<a;j++){
			if(vecE[i]==vecE[j]){
				cont++;
			}
		}
		if(max_cont<cont){
			moda=vecE[i];
			max_cont=cont;
		}
	}
	return(moda);
}

float promedio_general(float vecP[], int a){
	int i;
	float prom,suma=0;
	for(i=0;i<a;i++){
		suma=suma+vecP[i];
	}
	prom=suma/a;
	return(prom);
	
}

void ingresar_prom(float vecP[], int a){
	int i;
	for(i=0;i<a;i++){
		do{
			printf("Ingrese el promedio del alumno %d:  ", (i+1));
		    scanf("%f", &vecP[i]);
		    if(vecP[i]<1 || vecP[i]>7){
		    	printf("\n\n*ERROR* Ingrese un promedio valido entre 1 y 7\n\n");
			}
		}while(vecP[i]<1 || vecP[i]>7);
	}
}
void ingresar_random_prom(float vecP[], int a){
	srand(time (NULL));
	int i;
	for(i=0;i<a;i++){
		vecP[i]=(rand()%7)+1;
	}
}
void mostrar_prom(float vecP[], int a){
	int i;
	printf("\nLos promedios son: \n");
	for(i=0;i<a;i++){
		printf("[%.2f]", vecP[i]);
	}
}

void ingresar_edad(int vecE[], int a){
	int i;
	for(i=0;i<a;i++){
		do{
			printf("Ingrese la edad del alumno %d:  ", (i+1));
		    scanf("%d", &vecE[i]);
		    if(vecE[i]<14 || vecE[i]>20){
		    	printf("\n\n*ERROR Ingrese una edad valida entre 14 y 20\n\n");
			}
		}while(vecE[i]<14 || vecE[i]>20);
		
	}
}
void ingresar_random_edad(int vecE[], int a){
	srand(time (NULL));
	int i;
	for(i=0;i<a;i++){
		vecE[i]=(rand()%7)+14;
	}
}
void mostrar_edad(int vecE[], int a){
	int i;
	printf("\nLas edades son: \n");
	for(i=0;i<a;i++){
		printf("[%d]", vecE[i]);
	}
}

