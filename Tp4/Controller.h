/** \brief un controlador que se usa para cargar un archivo en modo de texto
 *
 * \param path char* el archivo seleccionado
 * \param pArrayListCar LinkedList* puntero al array creado
 * \return int retorna -1->error
 *                      0->todo ok
 */
int controller_loadFromText(char* path , LinkedList* pArrayListCar);


/** \brief un controlador que se usa para agregar un auto
 *
 * \param pArrayListCar LinkedList* puntero al array creado
 * \return int retorna -1->error
 *                      0->todo ok
 */
int controller_addCar(LinkedList* pArrayListCar);


/** \brief un controlador que se usa para modificar un auto
 *
 * \param pArrayListCar LinkedList* puntero al array creado
 * \return int retorna -1->error
 *                      0->todo ok
 */
int controller_editCar(LinkedList* pArrayListCar);


/** \brief un controlador que se usa para eliminar un auto
 *
 * \param pArrayListCar LinkedList* puntero al array creado
 * \return int retorna -1->error
 *                      0->todo ok
 */
int controller_removeCar(LinkedList* pArrayListCar);


/** \brief un controlador que se usa para listar los empleados
 *
 * \param pArrayListCar LinkedList* puntero al array creado
 * \return int retorna -1->error
 *                      0->todo ok
 */
int controller_ListCar(LinkedList* pArrayListCar);


/** \brief un controlador que se usa para ordenar un auto
 *
 * \param pArrayListCar LinkedList* puntero al array creado
 * \return int retorna -1->error
 *                      0->todo ok
 */
int controller_sortCar(LinkedList* pArrayListCar);


/** \brief un controlador que se usa para guardar un archivo en modo de texto
 *
 * \param path char* el archivo seleccionado
 * \param pArrayListCar LinkedList* puntero al array creado
 * \return int retorna -1->error
 *                      0->todo ok
 */
int controller_saveAsText(char* path , LinkedList* pArrayListCar);

