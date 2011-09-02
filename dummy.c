/* We make a dummy function calling OMX_Init() 
   This will pull in all the dependencies we have
 */
int OMX_Init();

void dummy_function(){
    OMX_Init();
}