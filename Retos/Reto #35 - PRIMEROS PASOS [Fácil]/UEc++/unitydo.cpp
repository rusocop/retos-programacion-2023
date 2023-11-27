// Imprimir "Hola mundo" en la consola
    UE_LOG(LogTemp, Warning, TEXT("¡Hola mundo desde Unreal Engine!"));

//Tipos de datos de texto
//Unreal distingue tres FString,FText , FName
//FString es una cadena de texto parecida a una variable string solo que Unreal utiliza una estructura propia para realizar operativa de cadenas llamada FString
 // Crear una variable FString
    FString MyFString = TEXT("Hola, esto es una FString");

//FText son textos que tienen una peculiraridad pueden ser localizados para ser traducidos más facilmente
   // Crear una variable FText
    FText MyFText = FText::FromString(TEXT("¡Hola, esto es un FText!"));

//FName es un tipo de texto que guarda una clave inmutable para facilitar la creación de IDs únicos para texto, mejorando por ejemplo la comparación de cadenas al hacer una comparación por clave hash en lugar de por caracteres
// Crear una variable FName
    FName MyFName = FName(TEXT("MiNombre"));

//Numeros enteros de 8,16,32 o 64 bits
int8=1;
int16=20;
//int32 es el int por defecto que crea Unreal al usar Blueprints, una de las ventajas de la programación en c++ es el ahorro de recursos al elegir otros tipos de variables más pequeñas según las necesidades
int32=23;
int64=10;
//existen como en c++ versiones de enteros sin signo uint8,uint16,uint32,uint64
uint32=2;

//Numeros decimales por defecto en blueprint se usa float
float distancia=3.0f;
// mas preciso
double decimalPreciso=4.5656f;

//Booleanas igual q en c++ excepto que se aconseja el uso de del prefijo b delante
//este prefijo no se muestra si se aparece en un blueprint
bEstaMuerto=false;

//Constantes son como en c++ cualquier tipo puede ser constante añadiendo el prefijo const
const int8 VidaInicial=100;

//CONTROL DE FLUJO
//operadores logicos
< menor que
> mayor que
<= menor o igual q
>= mayor o igual q
&& Y logico
|| Or logico
! Not
//interruptor logico
bEncendido=!bEncendido;
//if igual q en c++ la indentación solo es visual
if(EstamMuerto){
  GameOver();
}
//if else igual q en c++, la indentación solo es visual
if(distanciaRango<100){
  Ataca();
}else{
  BuscaPosicion();
}
//if else if igual q en c++, la indentación solo es visual
if(vidaEnemigo<20){
  Huye();
}else if(!Herido){
  Ataca();
}

//COLECCIONES
//Arrays aun que Unreal puede usar arrays de c++ se prefiere usar su propia estructura Tarray para crear matrices con algunas funciones implementadas como busqueda, borrar, añadir por lo que funcionan como Listas
 // Crear un TArray de enteros
    TArray<int32> Posiciones;

    // Agregar elementos al TArray
    Posiciones.Add(1);
    Posiciones.Add(2);
    Posiciones.Add(3);

    // Acceder a elementos del TArray
    int32 PrimeraPosicion = Posiciones[0];
    int32 SegundaPosicion = Posiciones[1];

//Tuplas sinceramente nunca he utilizado una en videojuegos solo se pueden usar en c++ ,se usan mucho más matrices de estructuras pero seguro que hay casos utiles, seria genial que alguien aporte caso de uso 
// Crear una tupla con los días de la semana
    FTuple<FString, FString, FString, FString, FString, FString, FString> daysOfWeek(
        TEXT("Lunes"),
        TEXT("Martes"),
        TEXT("Miércoles"),
        TEXT("Jueves"),
        TEXT("Viernes"),
        TEXT("Sábado"),
        TEXT("Domingo")
    );

    // Acceder a los elementos de la tupla
    FString monday = daysOfWeek.Get<0>();
    FString sunday = daysOfWeek.Get<6>();

    // Imprimir los días de la semana
    UE_LOG(LogTemp, Warning, TEXT("Día 1: %s"), *monday);
    UE_LOG(LogTemp, Warning, TEXT("Día 7: %s"), *sunday);

//Set los sets tampoco se usan mucho, aunq por estar expuestos en Blueprint son mas conocidos
// Crear un TSet para almacenar gemas recolectadas
    TSet<EGemType> CollectedGems;

    // Agregar gemas recolectadas al TSet
    CollectedGems.Add(GemType);

    // Comprobar si la gema ya ha sido recolectada
    if (CollectedGems.Contains(GemType))
    {
        UE_LOG(LogTemp, Warning, TEXT("¡Ya has recolectado esta gema!"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("¡Gema recolectada con éxito!"));
    }
//Los Diccionarios se llaman Maps se pueden crear tambien en blueprint lo que hace que junto con las matrices sean las colecciones mas utilizadas en Unreal
// Crear un TMap para representar el inventario de recursos
    TMap<FName, int32> InventarioRecursos;

    // Agregar recursos al inventario
    InventarioRecursos.Add(NombreRecurso, Cantidad);

//BUCLES
// while se utiliza poco, cuando es necesario hacer un bucle sin saber el número de vueltas se suele utilizar un Tick o un Timer
bool bRompecabezasResuelto = false;

    // Simulamos un rompecabezas interactivo
    while (!bRompecabezasResuelto)
    {
      if(Resuelve()){
        bRompecabezasResuelto=true;
      }
    }
// foreach en blueprint es el tipo de for más utilizado
// Iterar sobre los recursos en la mochila utilizando un bucle for each
    for (const FString& Recurso : RecursosEnMochila)
    {
        UE_LOG(LogTemp, Warning, TEXT("Procesando recurso en mochila: %s"), *Recurso);
        // Realizar alguna acción en el recurso, como usarlo o mostrarlo en pantalla
    }
//for su uso en c++ da la ventaja de realizar otro tipo de bucles que no son elemento a elemento como cada 2 elementos, de final a principio etc
 
  TArray<FVector> Posiciones;

    Posiciones.Add(FVector(10.0f, 20.0f, 30.0f));
    Posiciones.Add(FVector(-5.0f, 0.0f, 15.0f));
    Posiciones.Add(FVector(100.0f, -50.0f, 75.0f));
    Posiciones.Add(FVector(0.0f, 0.0f, 0.0f));
    Posiciones.Add(FVector(30.0f, 10.0f, 50.0f));
//Curiosidad en blueprint la longitud de una matriz se define con Lenght en c++ usa Num()
int32 Longitud = Posiciones.Num();
    // Recorrer todas las posiciones utilizando un bucle for
    for (int32 i = 0; i < Longitud; ++i)
    {
        FVector Posicion = Posiciones[i];
        UE_LOG(LogTemp, Warning, TEXT("Posición #%d: X=%.2f, Y=%.2f, Z=%.2f"), i + 1, Posicion.X, Posicion.Y, Posicion.Z);
    }
//Funciones como en c++ las funciones se declaran en el encabezado h y se definen en el cuerpo cpp
//Para facilitar a Unreal la consistencia del codigo se pone la Macro UFunction antes de la declaracion
//Funciones que no devuelven ningun valor, se considera devolver un vacio, se pone void delante de la función
//Sin Parametros () 
//En .h
UFUNCTION()
void HazAlgo();
//En .cpp
void APersonaje::HazAlgo(){
    UE_LOG(LogTemp, Warning, TEXT("Hago algo"));
}

//En .h
 UFUNCTION(BlueprintCallable, Category = "Math|MyLibrary")
   int32 Sumar(int32 A, int32 B);
//En .cpp
#include "MyMathLibrary.h" // Asegúrate de incluir los encabezados necesarios

int32 UMyMathLibrary::Sumar(int32 A, int32 B)
{
    return A + B;
}

 * - Crea una clase.

//Crear una clase
//Aun que se puede crear una clase directamente en Visual Studio, por comodidad en cuanto a generar automaticamente los archivos .h y cpp y q Unreal los coloque
//en sus respectivas carpetas es preferible crear la clase desde Unreal
//El primer paso es elegir de que clase va a heredar todas las clases de Unreal dependen de Object como clase más abstracta, no obstante es raro que tengamos que crear
//una clase derivada de Object, lo más comun es derivar de Actor, Character etc
//En .h
//Unreal es bastante estricto con algunas cuestiones 1 añade un prefijo segun el tipo de clase por ejemplo a Actor le añade A
//La ultima linea de referencias a librerias no puede ser modificada de orden, siempre debe ser la ultima #include "MiActorPersonalizado.generated.h"
//Obliga a tener una macro UCLASS como definidor de clase aunque declare class antes de la definición
//Debe tener un constructor definido aunque no tenga nada implementado

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MiActorPersonalizado.generated.h"

UCLASS()
class PROYECTOUNREAL_API AMiActorPersonalizado : public AActor
{
    GENERATED_BODY()

public:
    // Constructor
    AMiActorPersonalizado();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;
};
//En el .cpp
#include "MiActorPersonalizado.h"

// Constructor
AMiActorPersonalizado::AMiActorPersonalizado()
{
    // Establecer cualquier configuración específica del actor aquí.
}

void AMiActorPersonalizado::BeginPlay()
{
    Super::BeginPlay();
    // Lógica a realizar al comienzo del juego.
}

void AMiActorPersonalizado::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    // Lógica a realizar cada frame.
}

//Control de excepciones
//Quiza la mas utilizada es controlar que un objeto sea nulo
if (ActorPtr.IsValid())
{
   
    ActorPtr->HaceAlgo();
}
else
{
    // El puntero es nulo, manejar la situación de manera adecuada
    UE_LOG(LogTemp, Warning, TEXT("El puntero al actor es nulo."));
}
// Unreal tiene problemas con los try catch asi que usa libreria de asserts
 checkf(Value > 0, TEXT("El valor proporcionado (%d) debe ser positivo."), Value);
//En vez de recoger excepciones recoge "Alarmas" cuando algo no esta bien, salta la alarma.
