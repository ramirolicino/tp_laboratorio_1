/** \brief Muesta un menu de opciones
 *
 * \param numA int numero ingresado
 * \param numB int numero ingresado
 * \param flagA int determina si ya selccionaste esa opcion
 * \param flagB int determina si ya selccionaste esa opcion
 * \param flagC int determina si ya selccionaste esa opcion
 * \return char retorna la opcion ingresada
 *
 */
char menu(int numA, int numB, int flagA, int flagB, int flagC);

/** \brief Pide el ingreso de un numero
 *
 * \param mensaje[] char Muestra el mensaje escrito
 * \return int retorna el numero ingresado
 *
 */
int getInt(char mensaje[]);

/** \brief Muestra los resultdos de las operaciones
 *
 * \param numA int numero ingresado
 * \param numB int numero ingresado
 * \param suma int muestra la suma
 * \param resta int muestra la resta
 * \param division float muestra la division
 * \param multiplicacion int muestra la multiplicacion
 * \param factorialA long longint muestra el factorial
 * \param factorialB long longint muestra el factorial
 * \return void
 *
 */
void informeResultados(int numA, int numB, int suma,int resta,float division,int multiplicacion,long long int factorialA, long long int factorialB);


//****************** OPERACIONES **********************//

/** \brief realiza la suma de los numeros ingresados
 *
 * \param numA int numero ingesado
 * \param numB int numero ingesado
 * \return int retorna el resultado de la suma
 *
 */
int sumar(int numA, int numB);

/** \brief realiza la resta de los numeros ingresados
 *
 * \param numA int numero ingesado
 * \param numB int numero ingesado
 * \return int retorna el resultado de la resta
 *
 */
int restar(int numA, int numB);

/** \brief realiza la division de los numeros ingresados
 *
 * \param numA int numero ingesado
 * \param numB int numero ingesado
 * \return float retorna el resultado de la division
 *
 */
float dividir(int numA, int numB);

/** \brief realiza la multiplicacion de los numeros ingresados
 *
 * \param numA int numero ingesado
 * \param numB int numero ingesado
 * \return int retorna el resultado de la multiplicacion
 *
 */
int multiplicacion(int numA, int numB);

/** \brief realiza el factorial de los numeros ingresados
 *
 * \param numA int numero ingesado
 * \return int retorna el resultado del factorial
 *
 */
long long int Factorial(int numero);
