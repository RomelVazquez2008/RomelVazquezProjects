#Romel Aldair Vázquez Molina A01700519
"""IMPORTANTE: como este programa usa una imagen, se debe de extraer el zip a una carpeta junto con la imagen
si no el programa en automático lanzará error al compilar"""

"""ENTREGA FINAL"""

"""Separé esto del main, debido a que para mí es más comodo solo dejar la parte lógica hasta abajo, mientras esto solo es
para que se inicie pygame, se extraiga la imagen, se importen las librerias y las tipografías de los textos"""
import pygame #importo la libreria pygame
from pygame.locals import * #esto sirve para que no tenga que escribir pygame, al inicio de cada funcion que sea parte de la lybreria pygame, al menos en la mayoría de estos
import sys #esto sirve para la interacción de la ventana que se abre
import random #esto sirve para el numero aleatorio
import keyboard #esto sirve para el teclado
import time #Se importa el tiempo para restrasar el juego

SCREEN_WIDTH=1280 #esto es el largo de la pantalla
SCREEN_HEIGHT=800 #esto es el ancho de la pantalla
pygame.init() #por lo que entedí esta es la clave fundamental, porque inicia todo lo relacionado con pygame
pygame.font.init() #esto hace que se inicie la fuente del texto
myfont=pygame.font.SysFont('Comic Sans MS',30) #se declara la tipografía como comic sans y de tamaño 30
screen=pygame.display.set_mode((SCREEN_WIDTH,SCREEN_HEIGHT)) #aqui se abre la pantalla
pygame.display.set_caption("Mi juego") #este solo es el nombre de la ventana
imagen_vidas=pygame.image.load("corazon.jpg") #Aquí lo que hice fue cargar una imagen como las vidas
reloj=pygame.time.Clock() #Aquí se manda a llamar un objeto que funciona como un cronometro para medir el tiempo

#Algoritmo de la funcion dibujar_teclado
#dibujar_teclado (TECLAS, PANTALLA)EO
#    teclado=[[30,70,100],[100,200,300],[76,116,146],[120,220,320]]
#    indice_interior=0
#    x1teclado=teclado[0][indice_interior]
#    y1teclado=teclado[1][indice_interior]
#    xtext=teclado[2][indice_interior]
#    ytext=teclado[3][indice_interior]
#    largo=122
#    ancho=100
#    construidos=0
#    MIENTRAS (construidos!=26):
#        DIBUJAR CUADRADO(PANTALLA,BLANCO,x1teclado,y1teclado,largo,ancho)
#        ESCRIBIR(TECLAS[construidos],(xtexto,ytexto))
#        construidos=construidos+1
#        x1teclado=x1teclado+122
#        xtexto=xtexo+122
#        SI(construidos==10)
#            indice_interior=indice_interior+1
#            x1teclado=teclado[0][indice_interior]
#            y1teclado=teclado[1][indice_interior]
#            xtext=teclado[2][indice_interior]
#            ytext=teclado[3][indice_interior]
#        SI(construidos==19)
#            indice_interior=indice_interior+1
#            x1teclado=teclado[0][indice_interior]
#            y1teclado=teclado[1][indice_interior]
#            xtext=teclado[2][indice_interior]
#            ytext=teclado[3][indice_interior]
#     REGRESA 0 EF
def dibujar_teclado():
    teclado=[[30,70,100],[100,200,300],[76,116,146],[120,220,320]] #Donde la localidad 0 del arreglo exterior son las x del teclado,
    #localidad 1 para la y del teclado, localidad 2 para la x del texto y la localidad 3 para la y del texto
    indice_interior=0
    x1teclado=teclado[0][indice_interior]
    y1teclado=teclado[1][indice_interior]
    xtext=teclado[2][indice_interior]
    ytext=teclado[3][indice_interior]
    largo=122
    ancho=100
    construidos=0
    while (construidos!=26): #este ciclo lo que hace, es que se dibujen 26 teclas
        pygame.draw.rect(screen,(255,255,255),(x1teclado,y1teclado,largo,ancho),1) #esto construye un rectangulo con el contorno de color blanco
        textsurface=myfont.render(TECLAS[construidos],False,(255,0,0)) #esto añade a la variable textsurface los atributos de lo que se va a escribir
        screen.blit(textsurface,(xtext,ytext)) #y esto la escribe
        construidos=construidos+1
        x1teclado=x1teclado+122
        xtext=xtext+122
        if(construidos==10):
            indice_interior=indice_interior+1
            x1teclado=teclado[0][indice_interior]
            y1teclado=teclado[1][indice_interior]
            xtext=teclado[2][indice_interior]
            ytext=teclado[3][indice_interior]
        if(construidos==19):
            indice_interior=indice_interior+1
            x1teclado=teclado[0][indice_interior]
            y1teclado=teclado[1][indice_interior]
            xtext=teclado[2][indice_interior]
            ytext=teclado[3][indice_interior]

#Algoritmo de la funcion pintar_tecla
#pintar_tecla (TECLAS,pintar,PANTALLA) EO
#    teclado=[[30,70,100],[100,200,300],[76,116,146],[120,220,320]]
#    indice_interior=0
#    x1teclado=teclado[0][indice_interior]
#    y1teclado=teclado[1][indice_interior]
#    xtext=teclado[2][indice_interior]
#    ytext=teclado[3][indice_interior]
#    largo=30
#    ancho=30
#    posicion=0
#    MIENTRAS (posicion!=pintar):
#        posicion=posicion+1
#        x1teclado=x1teclado+30
#        xtext=xtext+30
#        SI(posicion==10)
#            indice_interior=indice_interior+1
#            x1teclado=teclado[0][indice_interior]
#            y1teclado=teclado[1][indice_interior]
#            xtext=teclado[2][indice_interior]
#            ytext=teclado[3][indice_interior]
##        SI(posicion==19)
#            indice_interior=indice_interior+1
#            x1teclado=teclado[0][indice_interior]
#            y1teclado=teclado[1][indice_interior]
#            xtext=teclado[2][indice_interior]
#            ytext=teclado[3][indice_interior]
#     DIBUJAR CUADRADO (PANTALLA,AZUL,x1teclado,y1teclado,largo,ancho)
#     ESCRIBIR(PANTALLA,TECLAS(posicion),(xtexto,ytexto))
#     REGRESA 0 EF
def pintar_tecla(letra_a_presionar):
    #Estas variables lo que hacen es idetificar una de las posibles 26 teclas que hay en todo el juego
    posicion=0
    teclado=[[30,70,100],[100,200,300],[76,116,146],[120,220,320]]
    indice_interior=0
    x1teclado=teclado[0][indice_interior]
    y1teclado=teclado[1][indice_interior]
    xtext=teclado[2][indice_interior]
    ytext=teclado[3][indice_interior]
    largo=122
    ancho=100
    while (posicion!=letra_a_presionar): #por otra parte este ciclo busca de 1 al 26, hasta que la tecla que se haya llamado de tecla_a_presionar sea la indicada
        x1teclado=x1teclado+122
        xtext=xtext+122
        posicion=posicion+1
        if(posicion==10):
            indice_interior=indice_interior+1
            x1teclado=teclado[0][indice_interior]
            y1teclado=teclado[1][indice_interior]
            xtext=teclado[2][indice_interior]
            ytext=teclado[3][indice_interior]
        if(posicion==19):
            indice_interior=indice_interior+1
            x1teclado=teclado[0][indice_interior]
            y1teclado=teclado[1][indice_interior]
            xtext=teclado[2][indice_interior]
            ytext=teclado[3][indice_interior]
    pygame.draw.rect(screen,(255,255,0),(x1teclado,y1teclado,largo,ancho)) #finalmente al salir del ciclo dibuja un rectángulo sobre esa tecla
    textsurface=myfont.render(TECLAS[posicion],False,(255,0,0)) #además se escribe otra vez la tecla, ya que si no solo queda el rectangulo
    screen.blit(textsurface,(xtext,ytext))
    
#Algoritmo de la funcion despintar_tecla
#despintar_tecla (TECLAS,pintar,PANTALLA) EO
#    teclado=[[30,70,100],[100,200,300],[76,116,146],[120,220,320]]
#    indice_interior=0
#    x1teclado=teclado[0][indice_interior]
#    y1teclado=teclado[1][indice_interior]
#    xtext=teclado[2][indice_interior]
#    ytext=teclado[3][indice_interior]
#    largo=30
#    ancho=30
#    posicion=0
#    MIENTRAS (posicion!=pintar):
#        posicion=posicion+1
#        x1teclado=x1teclado+30
#        xtext=xtext+30
#        SI(posicion==10)
#            indice_interior=indice_interior+1
#            x1teclado=teclado[0][indice_interior]
#            y1teclado=teclado[1][indice_interior]
#            xtext=teclado[2][indice_interior]
#            ytext=teclado[3][indice_interior]
##        SI(posicion==19)
#            indice_interior=indice_interior+1
#            x1teclado=teclado[0][indice_interior]
#            y1teclado=teclado[1][indice_interior]
#            xtext=teclado[2][indice_interior]
#            ytext=teclado[3][indice_interior]
#     DIBUJAR CUADRADO (PANTALLA,NEGRO,x1teclado,y1teclado,largo,ancho)
#     ESCRIBIR(PANTALLA,TECLAS(posicion),(xtexto,ytexto))
#     REGRESA 0 EF
"""Retomando el tema de la anterior entrega, es el mismo algoritmo que el de pintar tecla, solo pinta un cuadrado de color negro"""
def despintar_tecla(letra_a_presionar):
    posicion=0
    teclado=[[30,70,100],[100,200,300],[76,116,146],[120,220,320]]
    indice_interior=0
    x1teclado=teclado[0][indice_interior]
    y1teclado=teclado[1][indice_interior]
    xtext=teclado[2][indice_interior]
    ytext=teclado[3][indice_interior]
    largo=122
    ancho=100
    while (posicion!=letra_a_presionar):
        x1teclado=x1teclado+122
        xtext=xtext+122
        posicion=posicion+1
        if(posicion==10):
            indice_interior=indice_interior+1
            x1teclado=teclado[0][indice_interior]
            y1teclado=teclado[1][indice_interior]
            xtext=teclado[2][indice_interior]
            ytext=teclado[3][indice_interior]
        if(posicion==19):
            indice_interior=indice_interior+1
            x1teclado=teclado[0][indice_interior]
            y1teclado=teclado[1][indice_interior]
            xtext=teclado[2][indice_interior]
            ytext=teclado[3][indice_interior]
    pygame.draw.rect(screen,(0,0,0),(x1teclado,y1teclado,largo,ancho)) 
    textsurface=myfont.render(TECLAS[posicion],False,(255,0,0))
    screen.blit(textsurface,(xtext,ytext))
    
#Algoritmo de la funcion dibujar_vidas
#dibujar_vidas(nombre_archivo_jpg) EO
#    ESCRIBIR(PANTALLA,"Vidas",(50,500))
#    xvidas=150
#    vidas=0
#    MIENTRAS (vidas NO SEA IGUAL A 3)
#        INSERTAR(nombre_archivo_jpg,(xvidas,500))
#        vidas=vidas+1
#        xvidas=xvidas+60
#    xvidas=xvidas-60
#    REGRESA (vidas,xvidas) EF
def dibujar_vidas():
    textsurface=myfont.render("Vidas: ",False,(0,255,0))
    screen.blit(textsurface,(50,500))
    xvidas=150 #Esta variable es para poner una vida a la derecha de la otra en el eje de las x
    vidas=0
    while (vidas!=3): #este ciclo pone la imagen de las vidas, una a lado de la otra
        screen.blit(imagen_vidas,(xvidas,500)) 
        vidas=vidas+1
        xvidas=xvidas+60
    xvidas=xvidas-60 #esto lo pongo, porque al final me da un valor extra en xvidas, el cual no afecta esta función pero si a la de borra_vidas
    return (vidas, xvidas)

#Algoritmo de la funcion borrar_vidas
#dibujar_vidas(xvidas) EO
#    DIBUJAR CUADRADO (PANTALLA,NEGRO,xvidas,500,50,50)
#    xvidas=xvidas-60
#    REGRESA (xvidas) EF
def borrar_vida(xvidas):
    pygame.draw.rect(screen,(0,0,0),(xvidas,500,50,50)) #básicamente esta función solo dibuja un cuadrado de color negro y ya
    xvidas=xvidas-60 #esto lo descuenta, por el usuario vuelve a equivocarse y se tenga la futura posicion del eje de las x en que se ponga el siguiente cuadrado
    return(xvidas)

#Algoritmo de la funcion dibujar_puntuacion
#dibujar_puntuacion(puntuacion): EO
#    ESCRIBRI(PANTALLA,"PUNTUACION",(800,500))
#    ESCRIBIR(PANTALLA,puntuacion,(970,500))
#    REGRESA 0 EF
def dibujar_puntuacion(puntuacion):
    textsurface=myfont.render("Puntuacion: ",False,(0,255,175))
    screen.blit(textsurface,(800,500))
    pygame.draw.rect(screen,(0,0,0),(970,500,100,100)) #este rectangulo se dibuja para que el texto no se sobreponga uno sobre otro
    texto_puntuacion=str(puntuacion) #por alguna razón la función textsurface no puede escribir variables de tipo int, por lo que esto convierte la variable de formato int a string
    textsurface=myfont.render(texto_puntuacion,False,(0,255,175))
    screen.blit(textsurface,(970,500))

#Algoritmo de la función calcular_racha_y_streak
#calcular_racha_y_streak(racha,streak,limite) EO
    #racha=racha+1
    #SI (racha%10==0):
        #streak=streak+1
        #limite=limite-(limite*1/10
    #REGRESAR (racha, streak, limite) EF
def calcular_racha_y_streak(racha,streak,limite):
    racha=racha+1
    if (racha%10==0):
        streak=streak+1
        limite=limite-(limite*1/10) #Añadí de una vez el límite aquí para no crear una nueva función
    return(racha,streak,limite)

#Algoritmo de la función dibujar_streak
#dibujar_streak(streak) EO
#    ESCRIBRI(PANTALLA,"STREAK: X",(800,600))
#    DIBUJAR CUADRADO (PANTALLA,NEGRO,950,600,100,100)
#    ESCRIBIR(PANTALLA,streak,(950,600))
#    REGRESA 0 EF
def dibujar_streak(streak):
    textsurface=myfont.render("Streak: X",False,(255,150,0))
    screen.blit(textsurface,(800,600))
    pygame.draw.rect(screen,(0,0,0),(950,600,100,100)) #rectángulo que borra el número, después de recibir uno nuevo
    texto_streak=str(streak) 
    textsurface=myfont.render(texto_streak,False,(255,150,0))
    screen.blit(textsurface,(950,600))

#Algoritmo de la función dibujar_racha
#dibujar_racha(racha) EO
#    ESCRIBIR(PANTALLA,"RACHA: ",(50,600))
#    DIBUJAR CUADRADO (PANTALLA,NEGRO,150,600,100,100)
#    ESCRIBIR(PANTALLA,racha,(150,600))
#    REGRESA 0 EF
def dibujar_racha(racha):
    textsurface=myfont.render("Racha: ",False,(127,0,252))
    screen.blit(textsurface,(50,600))
    pygame.draw.rect(screen,(0,0,0),(150,600,100,100)) #rectángulo que borra el número, después de recibir uno nuevo
    texto_racha=str(racha)
    textsurface=myfont.render(texto_racha,False,(127,0,252))
    screen.blit(textsurface,(150,600))

#Algoritmo de la función dibujar_tiempo
#dibujar_tiempo(limite,velocidad,borrar_velocidad) EO
#    ESCRIBIR(PANTALLA,"TIEMPO: ",(400,600))
#    DIBUJAR CUADRADO (PANTALLA,NEGRO,500,600,100,100)
#    ESCRIBIR(PANTALLA,(limite-velocidad),(550,600))
#    REGRESA 0 EF
def dibujar_tiempo(limite,velocidad,borrar_velocidad):
    textsurface=myfont.render("Tiempo: ",False,(255,0,247))
    screen.blit(textsurface,(400,600))
    pygame.draw.rect(screen,(0,0,0),(500,600,150,100)) #rectángulo que borra el número, después de recibir uno nuevo
    float_tiempo=float(limite-velocidad)
    string_tiempo=str("%.1f" % (float_tiempo, ))
    textsurface=myfont.render(string_tiempo,False,(255,0,247))
    screen.blit(textsurface,(550,600))
    
#Algoritmo de la función llenar_cadena(TECLAS)
#llenar_cadena(TECLAS) EO
#   letras=[]
#   numeros=[]
#   texto_letras_a_presionar=[]
#   contador=0
#   MIENTRAS contador NO SEA IGUAL A 5
#       AÑADIR NÚMERO ALEATORIO EN numeros
#       AÑADIR TECLAS[numeros[contador]]
#       texto_letras_a_presionar=texto_letras_a_presionar+letras[contador]
#   REGRRESA (letras,numeros,texto_letras_a_presionar) EF
def llenar_cadena(TECLAS):
    letras=[]
    numeros=[]
    texto_letras_a_presionar=""
    contador=0
    while contador!=5:
        numeros.append(random.randint(0,25))
        letras.append(TECLAS[numeros[contador]])
        texto_letras_a_presionar=texto_letras_a_presionar+letras[contador]+"-"
        contador=contador+1
    return(letras,numeros,texto_letras_a_presionar)

#Algoritmo de la función recorrer_cadena
#recorrer_cadena(numeros_letras_a_presionar,letras_a_presionar,texto_letras_a_presionar,TECLAS) EO
#    ELIMINAR LOCALIDAD 0 DE numeros_letras_a_presionar
#    ELIMINAR LOCALIDAD 0 DE letras_a_presionar
#    AÑADIR NÚMERO ALEATORIO EN numeros_letras_a_presionar
#    AÑADIR TECLAS[numeros_letras_a_presionar[4]] EN letras_a_presionar
#    texto_letras_a_presionar=""
#    PARA a EN letras_a_presionar
#         texto_letras_a_presionar=texto_letras_a_presionar+a
#    REGRESA (letras_a_presionar, numeros_letras_a_presionar,texto_letras_a_presionar) EF
def recorrer_cadena(numeros_letras_a_presionar,letras_a_presionar,texto_letras_a_presionar,TECLAS):
    numeros_letras_a_presionar.pop(0)
    letras_a_presionar.pop(0)
    numeros_letras_a_presionar.append(random.randint(0,25))
    letras_a_presionar.append(TECLAS[numeros_letras_a_presionar[4]])
    texto_letras_a_presionar=""
    for a in letras_a_presionar:
        texto_letras_a_presionar=texto_letras_a_presionar+a+"-"
    return(letras_a_presionar, numeros_letras_a_presionar,texto_letras_a_presionar)

#Algoritmo de la función dibuja_cadena
#dibuja_cadena(texto_letras_a_presionar) EO
#    ESCRIBIR(PANTALLA,"SIGUIENTE: ",(400,500))
#    DIBUJAR CUADRADO (PANTALLA,NEGRO,550,500,100,100)
#    ESCRIBIR(PANTALLA,texto_letras_a_presionar,(550,500))
#    REGRESA 0 EF
def dibuja_cadena(texto_letras_a_presionar):
    textsurface=myfont.render("Siguiente: ",False,(124,173,255))
    screen.blit(textsurface,(400,500))
    pygame.draw.rect(screen,(0,0,0),(550,500,200,100)) #rectángulo que borra la cadena, después de recibir una nueva
    textsurface=myfont.render(texto_letras_a_presionar,False,(124,173,255))
    screen.blit(textsurface,(550,500))

#Algoritmo de la funcion main()
#PRECONDICIONES: Haber importado las librerias, haber iniciado la pantalla main de pygame y tener una imagen en la carpeta donde se ubique este archivo avance proyecto benji.py
#main()
#   letra_a_presionar=random
#   TECLAS=['Q','W','E','R','T','Y','U','I','O','P','A','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M']
#   vidas, xvidas=LLAMAR dibujar_vidas()
#   letras_a_presionar,numero_letras_a_presionar,texto_letras_a_presionar=LLAMARA A FUNCIÓN llenar_cadena(TECLAS)
#   letra_a_presionar=numero_letras_a_presionar[0]
#   LLAMAR A FUNCIÓN dibuja_cadena(texto_letras_a_presionar)
#   puntuacion=0
#   LLAMAR dibujar_puntuacion(puntuacion)
#   limite=3
#   borrar_velocidad=0
#   streak=1
#   racha=0
#   LLAMAR A dibujar_streak(streak)
#   LLAMAR A dibujar_racha(racha)
#   MIENTRAS [verdad] HACER:
#       velocidad=OBTENER TIEMPO-borrar_velocidad
#       SI (velocidad>limite)
#           xvidas=LLAMAR A borrar_vida(xvidas)
#           vidas=vidas-1
#           borrar_velocidad=borrar_velocidad+velocidad
#       LLAMAR dibujar_teclado()
#       LLAMAR pintar_tecla(letra_a_presionar)
#       tecla_presionada=OBTENER TECLA
"""en este punto del algoritmo hay 26 condiciones de SI que se repiten, la unica difenrencia es que van de la tecla a a la z
por lo que solo definiré la de la tecla a, para no hacer repetitivo todo el algoritmo, en el código si estarán implementadas los
26 condicionles de SI"""
#        SI tecla_presionada==a
#            borrar_velocidad=borrar_velocidad+velocidad
#            SI tecla_presionada==letra_a_presionar
#                LLAMAR despintar_tecla(letra_a_presionar)
#                letras_a_presionar,numero_letras_a_presionar,texto_letras_a_presionar=LLAMAR A recorrer_cadena(numero_letras_a_presionar,letras_a_presionar,texto_letras_a_presionar,TECLAS)
#                LLAMAR A dibuja_cadena(texto_letras_a_presionar)
#                letra_a_presionar=numero_letras_a_presionar[0]
#                letra_a_presionar=random
#                puntuacion=puntuacion+20*streak
#                LLAMAR dibujar_puntuacion(puntuacion)
#                racha,streak=LLAMAR A calcular_racha_y_streak(racha,streak)
#                LLAMAR A dibujar_streak(streak)
#                LLAMAR A dibujar_racha(racha)
#            DE OTRA FORMA
#                xvidas=LLAMAR borrar_vida(xvidas)
#                vidas=vidas-1
#                puntuacion=puntuacion-200*streak
#                dibujar_puntuacion(puntuacion)
#                racha=0
#                LLAMAR A dibujar_racha(racha)
#                streak=1           
#                LLAMAR A dibujar_streak(streak)
#    SI vidas==0
#        CERRAR VENTANA

#
"""Casos de Prueba: Realmente no hay casos de prueba como tal, ya que depende mucho del azar del juego,
pero dentro de lo que puede pasar dentro del juego es lo siguiente:
-Cada tecla correcta consecutiva que el usuario teclé, agregará en uno a la racha
-Cada 10 rachas, se aumentará un streak, que al multiplicarla por los puntos obtenidos/perdidos, afectará la puntuación.
Además se descontará (1/10 * limite de tiempo) al tiempo que tiene el usuario para presionar una nueva tecla
-No hay límite de puntuación, racha o streak. 
-El sistema incrementará 20 puntos multiplicada por los streaks, a la puntuacion por cada tecla correcta que presiones
-El sistema elminia 200 puntos multiplicada por los streaks, a la puntuacion y elimina una vida si oprimes una tecla que no es la indicada
-La puntuación minima que puede haber es 0, eso significa que si el usuario se equivoca teniendo menos de 200 multiplicada por los streaks, el sistema siempre arrojará 0
-Transcurridos 3 segundos el usuario pierde una vida y se le resta la puntuación multiplicada por los streaks que lleve.
-Una vez que se borren las 3 vidas, el sistema espera 3 segundos, para posteriormente cerrar el programa

"""
TECLAS=['Q','W','E','R','T','Y','U','I','O','P','A','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M']
#El arreglo de TECLAS, es esencial ya que sirve en casi todas las funciones del juego para hacer validaciones entre el input del usuario
vidas, xvidas=dibujar_vidas()
letras_a_presionar,numero_letras_a_presionar,texto_letras_a_presionar=(llenar_cadena(TECLAS))
letra_a_presionar=numero_letras_a_presionar[0]
dibuja_cadena(texto_letras_a_presionar)
puntuacion=0
dibujar_puntuacion(puntuacion)
SUMAR_PUNTUACION=20 #estas constantes las definí así, ya que es más práctico por si se quieren realizar cambios
RESTAR_PUNTUACION=200
limite=3 #variable como el limite de la velocidad que puede tomar el reloj
borrar_velocidad=0 #esta variable sirve para borrar la velocidad después de un lapso de tiempo
streak=1 #esta variable es para multiplicar a la variable SUMAR_PUNTUACION, de acuerdo a la racha de acierto que tenga el usuario
racha=0#esta variable va a contar la racha del usuario
dibujar_streak(streak)
dibujar_racha(racha)
while True:
    
    velocidad=(pygame.time.get_ticks()/1000)-borrar_velocidad #aquí la variable de velocidad depende del objeto get_ticks, el cual cuenta el tiempo después de que se abre la ventana de pygame
    #por lo tanto, es necesario ir borrando la velocidad con otra variable, para que solo quede como resultado el cambio entre estas
    #que en pocas palabras tome los segundos después de oprimir una tecla
    if (velocidad>=limite): 
        xvidas=borrar_vida(xvidas)
        vidas=vidas-1
        racha=0
        dibujar_racha(racha)
        if(puntuacion>=RESTAR_PUNTUACION*streak):
            puntuacion=puntuacion-(RESTAR_PUNTUACION*streak)
            dibujar_puntuacion(puntuacion)
        else:
            puntuacion=0
            dibujar_puntuacion(puntuacion)
        borrar_velocidad=borrar_velocidad+velocidad #se aumenta la cantidad de segundos en ese lapso de tiempo, para que la variable de velocidad vuelva a ser 0
        streak=1
        dibujar_streak(streak)
    
    dibujar_tiempo(limite,velocidad,borrar_velocidad)
    
    if (vidas==0): #este if es para cerrar el juego, si se pierden todas las vidas
        time.sleep(3)#esto deja que pantalla abierta, para que el usuario tenga tiempo de ver su puntuación
        sys.exit()
    
    dibujar_teclado()
    pintar_tecla(letra_a_presionar)
    
    for event in pygame.event.get():
        
        if event.type==pygame.QUIT: #esto cierra el juego si el usuario presiona la "X" en la esquina superior derecha
            sys.exit()
        
        tecla_presionada=pygame.key.get_pressed() #el objeto key.get_pressed, admite la entradas del teclado, aunque a diferencia
#del entregable anterior, este es más preciso ya que no depende todo el tiempo de oprimir una tecla, solo cuando el usuario lo requiera
        
        if tecla_presionada[K_a]:#al igual que en el algoritmo, podría explicar cada if, pero son lo mismo,
#solo que cambia la tecla, así que solo explicaré el primero
            id_tecla_presionada=10 #este id sirve para identificar cada letra como un numero para la función de despintar_tecla
            borrar_velocidad=borrar_velocidad+velocidad #se aumenta la cantidad de segundos en ese lapso de tiempo, para que la variable de velocidad vuelva a ser 0
            if (id_tecla_presionada==letra_a_presionar):
                despintar_tecla(letra_a_presionar)
                letras_a_presionar,numero_letras_a_presionar,texto_letras_a_presionar=recorrer_cadena(numero_letras_a_presionar,letras_a_presionar,texto_letras_a_presionar,TECLAS)
                dibuja_cadena(texto_letras_a_presionar)
                letra_a_presionar=numero_letras_a_presionar[0]
                puntuacion=puntuacion+SUMAR_PUNTUACION*streak
                dibujar_puntuacion(puntuacion)
                racha,streak,limite=calcular_racha_y_streak(racha,streak,limite)
                dibujar_streak(streak)
                dibujar_racha(racha)
            else:
                xvidas=borrar_vida(xvidas)
                vidas=vidas-1
                racha=0
                dibujar_racha(racha)
                if(puntuacion>=RESTAR_PUNTUACION*streak): #Aquí es importante aclarar que no hay puntuaciones negativas, por lo que
#si la puntuación es menor a 200, siempre lo mínimo que puede regresar es 0
                    puntuacion=puntuacion-(RESTAR_PUNTUACION*streak)
                    dibujar_puntuacion(puntuacion)
                else:
                    puntuacion=0
                    dibujar_puntuacion(puntuacion)
                streak=1           
                dibujar_streak(streak)
            
        if tecla_presionada[K_b]:
            id_tecla_presionada=23
            borrar_velocidad=borrar_velocidad+velocidad
            if (id_tecla_presionada==letra_a_presionar):
                despintar_tecla(letra_a_presionar)
                letras_a_presionar,numero_letras_a_presionar,texto_letras_a_presionar=recorrer_cadena(numero_letras_a_presionar,letras_a_presionar,texto_letras_a_presionar,TECLAS)
                dibuja_cadena(texto_letras_a_presionar)
                letra_a_presionar=numero_letras_a_presionar[0]
                puntuacion=puntuacion+SUMAR_PUNTUACION*streak
                dibujar_puntuacion(puntuacion)
                racha,streak,limite=calcular_racha_y_streak(racha,streak,limite)
                dibujar_streak(streak)
                dibujar_racha(racha)
            else:
                xvidas=borrar_vida(xvidas)
                vidas=vidas-1
                racha=0
                dibujar_racha(racha)
                if(puntuacion>=RESTAR_PUNTUACION*streak):
                    puntuacion=puntuacion-(RESTAR_PUNTUACION*streak)
                    dibujar_puntuacion(puntuacion)
                else:
                    puntuacion=0
                    dibujar_puntuacion(puntuacion)
                streak=1           
                dibujar_streak(streak)
            

        if tecla_presionada[K_c]:
            id_tecla_presionada=21
            borrar_velocidad=borrar_velocidad+velocidad
            if (id_tecla_presionada==letra_a_presionar):
                despintar_tecla(letra_a_presionar)
                letras_a_presionar,numero_letras_a_presionar,texto_letras_a_presionar=recorrer_cadena(numero_letras_a_presionar,letras_a_presionar,texto_letras_a_presionar,TECLAS)
                dibuja_cadena(texto_letras_a_presionar)
                letra_a_presionar=numero_letras_a_presionar[0]
                puntuacion=puntuacion+SUMAR_PUNTUACION*streak
                dibujar_puntuacion(puntuacion)
                racha,streak,limite=calcular_racha_y_streak(racha,streak,limite)
                dibujar_streak(streak)
                dibujar_racha(racha)
            else:
                xvidas=borrar_vida(xvidas)
                vidas=vidas-1
                racha=0
                dibujar_racha(racha)
                if(puntuacion>=RESTAR_PUNTUACION*streak):
                    puntuacion=puntuacion-(RESTAR_PUNTUACION*streak)
                    dibujar_puntuacion(puntuacion)
                else:
                    puntuacion=0
                    dibujar_puntuacion(puntuacion)
                streak=1           
                dibujar_streak(streak)
            
        if tecla_presionada[K_d]:
            id_tecla_presionada=12
            borrar_velocidad=borrar_velocidad+velocidad
            if (id_tecla_presionada==letra_a_presionar):
                despintar_tecla(letra_a_presionar)
                letras_a_presionar,numero_letras_a_presionar,texto_letras_a_presionar=recorrer_cadena(numero_letras_a_presionar,letras_a_presionar,texto_letras_a_presionar,TECLAS)
                dibuja_cadena(texto_letras_a_presionar)
                letra_a_presionar=numero_letras_a_presionar[0]
                puntuacion=puntuacion+SUMAR_PUNTUACION*streak
                dibujar_puntuacion(puntuacion)
                racha,streak,limite=calcular_racha_y_streak(racha,streak,limite)
                dibujar_streak(streak)
                dibujar_racha(racha)
            else:
                xvidas=borrar_vida(xvidas)
                vidas=vidas-1
                racha=0
                dibujar_racha(racha)
                if(puntuacion>=RESTAR_PUNTUACION*streak):
                    puntuacion=puntuacion-(RESTAR_PUNTUACION*streak)
                    dibujar_puntuacion(puntuacion)
                else:
                    puntuacion=0
                    dibujar_puntuacion(puntuacion)
                streak=1           
                dibujar_streak(streak)

        if tecla_presionada[K_e]:
            id_tecla_presionada=2
            borrar_velocidad=borrar_velocidad+velocidad
            if (id_tecla_presionada==letra_a_presionar):
                despintar_tecla(letra_a_presionar)
                letras_a_presionar,numero_letras_a_presionar,texto_letras_a_presionar=recorrer_cadena(numero_letras_a_presionar,letras_a_presionar,texto_letras_a_presionar,TECLAS)
                dibuja_cadena(texto_letras_a_presionar)
                letra_a_presionar=numero_letras_a_presionar[0]
                puntuacion=puntuacion+SUMAR_PUNTUACION*streak
                dibujar_puntuacion(puntuacion)
                racha,streak,limite=calcular_racha_y_streak(racha,streak,limite)
                dibujar_streak(streak)
                dibujar_racha(racha)
            else:
                xvidas=borrar_vida(xvidas)
                vidas=vidas-1
                racha=0
                dibujar_racha(racha)
                if(puntuacion>=RESTAR_PUNTUACION*streak):
                    puntuacion=puntuacion-(RESTAR_PUNTUACION*streak)
                    dibujar_puntuacion(puntuacion)
                else:
                    puntuacion=0
                    dibujar_puntuacion(puntuacion)
                streak=1           
                dibujar_streak(streak)
                
                
        if tecla_presionada[K_f]:
            id_tecla_presionada=13
            borrar_velocidad=borrar_velocidad+velocidad
            if (id_tecla_presionada==letra_a_presionar):
                despintar_tecla(letra_a_presionar)
                letras_a_presionar,numero_letras_a_presionar,texto_letras_a_presionar=recorrer_cadena(numero_letras_a_presionar,letras_a_presionar,texto_letras_a_presionar,TECLAS)
                dibuja_cadena(texto_letras_a_presionar)
                letra_a_presionar=numero_letras_a_presionar[0]
                puntuacion=puntuacion+SUMAR_PUNTUACION*streak
                dibujar_puntuacion(puntuacion)
                racha,streak,limite=calcular_racha_y_streak(racha,streak,limite)
                dibujar_streak(streak)
                dibujar_racha(racha)
            else:
                xvidas=borrar_vida(xvidas)
                vidas=vidas-1
                racha=0
                dibujar_racha(racha)
                if(puntuacion>=RESTAR_PUNTUACION*streak):
                    puntuacion=puntuacion-(RESTAR_PUNTUACION*streak)
                    dibujar_puntuacion(puntuacion)
                else:
                    puntuacion=0
                    dibujar_puntuacion(puntuacion)
                streak=1           
                dibujar_streak(streak)
            
        if tecla_presionada[K_g]:
            id_tecla_presionada=14
            borrar_velocidad=borrar_velocidad+velocidad
            if (id_tecla_presionada==letra_a_presionar):
                despintar_tecla(letra_a_presionar)
                letras_a_presionar,numero_letras_a_presionar,texto_letras_a_presionar=recorrer_cadena(numero_letras_a_presionar,letras_a_presionar,texto_letras_a_presionar,TECLAS)
                dibuja_cadena(texto_letras_a_presionar)
                letra_a_presionar=numero_letras_a_presionar[0]
                puntuacion=puntuacion+SUMAR_PUNTUACION*streak
                dibujar_puntuacion(puntuacion)
                racha,streak,limite=calcular_racha_y_streak(racha,streak,limite)
                dibujar_streak(streak)
                dibujar_racha(racha)
            else:
                xvidas=borrar_vida(xvidas)
                vidas=vidas-1
                racha=0
                dibujar_racha(racha)
                if(puntuacion>=RESTAR_PUNTUACION*streak):
                    puntuacion=puntuacion-(RESTAR_PUNTUACION*streak)
                    dibujar_puntuacion(puntuacion)
                else:
                    puntuacion=0
                    dibujar_puntuacion(puntuacion)
                streak=1           
                dibujar_streak(streak)
            
        if tecla_presionada[K_h]:
            id_tecla_presionada=15
            borrar_velocidad=borrar_velocidad+velocidad
            if (id_tecla_presionada==letra_a_presionar):
                despintar_tecla(letra_a_presionar)
                letras_a_presionar,numero_letras_a_presionar,texto_letras_a_presionar=recorrer_cadena(numero_letras_a_presionar,letras_a_presionar,texto_letras_a_presionar,TECLAS)
                dibuja_cadena(texto_letras_a_presionar)
                letra_a_presionar=numero_letras_a_presionar[0]
                puntuacion=puntuacion+SUMAR_PUNTUACION*streak
                dibujar_puntuacion(puntuacion)
                racha,streak,limite=calcular_racha_y_streak(racha,streak,limite)
                dibujar_streak(streak)
                dibujar_racha(racha)
            else:
                xvidas=borrar_vida(xvidas)
                vidas=vidas-1
                racha=0
                dibujar_racha(racha)
                if(puntuacion>=RESTAR_PUNTUACION*streak):
                    puntuacion=puntuacion-(RESTAR_PUNTUACION*streak)
                    dibujar_puntuacion(puntuacion)
                else:
                    puntuacion=0
                    dibujar_puntuacion(puntuacion)
                streak=1           
                dibujar_streak(streak)
            
        if tecla_presionada[K_i]:
            id_tecla_presionada=7
            borrar_velocidad=borrar_velocidad+velocidad
            if (id_tecla_presionada==letra_a_presionar):
                despintar_tecla(letra_a_presionar)
                letras_a_presionar,numero_letras_a_presionar,texto_letras_a_presionar=recorrer_cadena(numero_letras_a_presionar,letras_a_presionar,texto_letras_a_presionar,TECLAS)
                dibuja_cadena(texto_letras_a_presionar)
                letra_a_presionar=numero_letras_a_presionar[0]
                puntuacion=puntuacion+SUMAR_PUNTUACION*streak
                dibujar_puntuacion(puntuacion)
                racha,streak,limite=calcular_racha_y_streak(racha,streak,limite)
                dibujar_streak(streak)
                dibujar_racha(racha)
            else:
                xvidas=borrar_vida(xvidas)
                vidas=vidas-1
                racha=0
                dibujar_racha(racha)
                if(puntuacion>=RESTAR_PUNTUACION*streak):
                    puntuacion=puntuacion-(RESTAR_PUNTUACION*streak)
                    dibujar_puntuacion(puntuacion)
                else:
                    puntuacion=0
                    dibujar_puntuacion(puntuacion)
                streak=1           
                dibujar_streak(streak)
        
        if tecla_presionada[K_j]:
            id_tecla_presionada=16
            borrar_velocidad=borrar_velocidad+velocidad
            if (id_tecla_presionada==letra_a_presionar):
                despintar_tecla(letra_a_presionar)
                letras_a_presionar,numero_letras_a_presionar,texto_letras_a_presionar=recorrer_cadena(numero_letras_a_presionar,letras_a_presionar,texto_letras_a_presionar,TECLAS)
                dibuja_cadena(texto_letras_a_presionar)
                letra_a_presionar=numero_letras_a_presionar[0]
                puntuacion=puntuacion+SUMAR_PUNTUACION*streak
                dibujar_puntuacion(puntuacion)
                racha,streak,limite=calcular_racha_y_streak(racha,streak,limite)
                dibujar_streak(streak)
                dibujar_racha(racha)
            else:
                xvidas=borrar_vida(xvidas)
                vidas=vidas-1
                racha=0
                dibujar_racha(racha)
                if(puntuacion>=RESTAR_PUNTUACION*streak):
                    puntuacion=puntuacion-(RESTAR_PUNTUACION*streak)
                    dibujar_puntuacion(puntuacion)
                else:
                    puntuacion=0
                    dibujar_puntuacion(puntuacion)
                streak=1           
                dibujar_streak(streak)

        if tecla_presionada[K_k]:
            id_tecla_presionada=17
            borrar_velocidad=borrar_velocidad+velocidad
            if (id_tecla_presionada==letra_a_presionar):
                despintar_tecla(letra_a_presionar)
                letras_a_presionar,numero_letras_a_presionar,texto_letras_a_presionar=recorrer_cadena(numero_letras_a_presionar,letras_a_presionar,texto_letras_a_presionar,TECLAS)
                dibuja_cadena(texto_letras_a_presionar)
                letra_a_presionar=numero_letras_a_presionar[0]
                puntuacion=puntuacion+SUMAR_PUNTUACION*streak
                dibujar_puntuacion(puntuacion)
                racha,streak,limite=calcular_racha_y_streak(racha,streak,limite)
                dibujar_streak(streak)
                dibujar_racha(racha)
            else:
                xvidas=borrar_vida(xvidas)
                vidas=vidas-1
                racha=0
                dibujar_racha(racha)
                if(puntuacion>=RESTAR_PUNTUACION*streak):
                    puntuacion=puntuacion-(RESTAR_PUNTUACION*streak)
                    dibujar_puntuacion(puntuacion)
                else:
                    puntuacion=0
                    dibujar_puntuacion(puntuacion)
                streak=1           
                dibujar_streak(streak)
            
        if tecla_presionada[K_l]:
            id_tecla_presionada=18
            borrar_velocidad=borrar_velocidad+velocidad
            if (id_tecla_presionada==letra_a_presionar):
                despintar_tecla(letra_a_presionar)
                letras_a_presionar,numero_letras_a_presionar,texto_letras_a_presionar=recorrer_cadena(numero_letras_a_presionar,letras_a_presionar,texto_letras_a_presionar,TECLAS)
                dibuja_cadena(texto_letras_a_presionar)
                letra_a_presionar=numero_letras_a_presionar[0]
                puntuacion=puntuacion+SUMAR_PUNTUACION*streak
                dibujar_puntuacion(puntuacion)
                racha,streak,limite=calcular_racha_y_streak(racha,streak,limite)
                dibujar_streak(streak)
                dibujar_racha(racha)
            else:
                xvidas=borrar_vida(xvidas)
                vidas=vidas-1
                racha=0
                dibujar_racha(racha)
                if(puntuacion>=RESTAR_PUNTUACION*streak):
                    puntuacion=puntuacion-(RESTAR_PUNTUACION*streak)
                    dibujar_puntuacion(puntuacion)
                else:
                    puntuacion=0
                    dibujar_puntuacion(puntuacion)
                streak=1           
                dibujar_streak(streak)
            
        if tecla_presionada[K_m]:
            id_tecla_presionada=25
            borrar_velocidad=borrar_velocidad+velocidad
            if (id_tecla_presionada==letra_a_presionar):
                despintar_tecla(letra_a_presionar)
                letras_a_presionar,numero_letras_a_presionar,texto_letras_a_presionar=recorrer_cadena(numero_letras_a_presionar,letras_a_presionar,texto_letras_a_presionar,TECLAS)
                dibuja_cadena(texto_letras_a_presionar)
                letra_a_presionar=numero_letras_a_presionar[0]
                puntuacion=puntuacion+SUMAR_PUNTUACION*streak
                dibujar_puntuacion(puntuacion)
                racha,streak,limite=calcular_racha_y_streak(racha,streak,limite)
                dibujar_streak(streak)
                dibujar_racha(racha)
            else:
                xvidas=borrar_vida(xvidas)
                vidas=vidas-1
                racha=0
                dibujar_racha(racha)
                if(puntuacion>=RESTAR_PUNTUACION*streak):
                    puntuacion=puntuacion-(RESTAR_PUNTUACION*streak)
                    dibujar_puntuacion(puntuacion)
                else:
                    puntuacion=0
                    dibujar_puntuacion(puntuacion)
                streak=1           
                dibujar_streak(streak)
            
        if tecla_presionada[K_n]:
            id_tecla_presionada=24
            borrar_velocidad=borrar_velocidad+velocidad
            if (id_tecla_presionada==letra_a_presionar):
                despintar_tecla(letra_a_presionar)
                letras_a_presionar,numero_letras_a_presionar,texto_letras_a_presionar=recorrer_cadena(numero_letras_a_presionar,letras_a_presionar,texto_letras_a_presionar,TECLAS)
                dibuja_cadena(texto_letras_a_presionar)
                letra_a_presionar=numero_letras_a_presionar[0]
                puntuacion=puntuacion+SUMAR_PUNTUACION*streak
                dibujar_puntuacion(puntuacion)
                racha,streak,limite=calcular_racha_y_streak(racha,streak,limite)
                dibujar_streak(streak)
                dibujar_racha(racha)
            else:
                xvidas=borrar_vida(xvidas)
                vidas=vidas-1
                racha=0
                dibujar_racha(racha)
                if(puntuacion>=RESTAR_PUNTUACION*streak):
                    puntuacion=puntuacion-(RESTAR_PUNTUACION*streak)
                    dibujar_puntuacion(puntuacion)
                else:
                    puntuacion=0
                    dibujar_puntuacion(puntuacion)
                streak=1           
                dibujar_streak(streak)
            
        if tecla_presionada[K_o]:
            id_tecla_presionada=8
            borrar_velocidad=borrar_velocidad+velocidad
            if (id_tecla_presionada==letra_a_presionar):
                despintar_tecla(letra_a_presionar)
                letras_a_presionar,numero_letras_a_presionar,texto_letras_a_presionar=recorrer_cadena(numero_letras_a_presionar,letras_a_presionar,texto_letras_a_presionar,TECLAS)
                dibuja_cadena(texto_letras_a_presionar)
                letra_a_presionar=numero_letras_a_presionar[0]
                puntuacion=puntuacion+SUMAR_PUNTUACION*streak
                dibujar_puntuacion(puntuacion)
                racha,streak,limite=calcular_racha_y_streak(racha,streak,limite)
                dibujar_streak(streak)
                dibujar_racha(racha)
            else:
                xvidas=borrar_vida(xvidas)
                vidas=vidas-1
                racha=0
                dibujar_racha(racha)
                if(puntuacion>=RESTAR_PUNTUACION*streak):
                    puntuacion=puntuacion-(RESTAR_PUNTUACION*streak)
                    dibujar_puntuacion(puntuacion)
                else:
                    puntuacion=0
                    dibujar_puntuacion(puntuacion)
                streak=1           
                dibujar_streak(streak)
            
        if tecla_presionada[K_p]:
            id_tecla_presionada=9
            borrar_velocidad=borrar_velocidad+velocidad
            if (id_tecla_presionada==letra_a_presionar):
                despintar_tecla(letra_a_presionar)
                letras_a_presionar,numero_letras_a_presionar,texto_letras_a_presionar=recorrer_cadena(numero_letras_a_presionar,letras_a_presionar,texto_letras_a_presionar,TECLAS)
                dibuja_cadena(texto_letras_a_presionar)
                letra_a_presionar=numero_letras_a_presionar[0]
                puntuacion=puntuacion+SUMAR_PUNTUACION*streak
                dibujar_puntuacion(puntuacion)
                racha,streak,limite=calcular_racha_y_streak(racha,streak,limite)
                dibujar_streak(streak)
                dibujar_racha(racha)
            else:
                xvidas=borrar_vida(xvidas)
                vidas=vidas-1
                racha=0
                dibujar_racha(racha)
                if(puntuacion>=RESTAR_PUNTUACION*streak):
                    puntuacion=puntuacion-(RESTAR_PUNTUACION*streak)
                    dibujar_puntuacion(puntuacion)
                else:
                    puntuacion=0
                    dibujar_puntuacion(puntuacion)
                streak=1           
                dibujar_streak(streak)
            
        if tecla_presionada[K_q]:
            id_tecla_presionada=0
            borrar_velocidad=borrar_velocidad+velocidad
            if (id_tecla_presionada==letra_a_presionar):
                despintar_tecla(letra_a_presionar)
                letras_a_presionar,numero_letras_a_presionar,texto_letras_a_presionar=recorrer_cadena(numero_letras_a_presionar,letras_a_presionar,texto_letras_a_presionar,TECLAS)
                dibuja_cadena(texto_letras_a_presionar)
                letra_a_presionar=numero_letras_a_presionar[0]
                puntuacion=puntuacion+SUMAR_PUNTUACION*streak
                dibujar_puntuacion(puntuacion)
                racha,streak,limite=calcular_racha_y_streak(racha,streak,limite)
                dibujar_streak(streak)
                dibujar_racha(racha)
            else:
                xvidas=borrar_vida(xvidas)
                vidas=vidas-1
                racha=0
                dibujar_racha(racha)
                if(puntuacion>=RESTAR_PUNTUACION*streak):
                    puntuacion=puntuacion-(RESTAR_PUNTUACION*streak)
                    dibujar_puntuacion(puntuacion)
                else:
                    puntuacion=0
                    dibujar_puntuacion(puntuacion)
                streak=1           
                dibujar_streak(streak)
            
        if tecla_presionada[K_r]:
            id_tecla_presionada=3
            borrar_velocidad=borrar_velocidad+velocidad
            if (id_tecla_presionada==letra_a_presionar):
                despintar_tecla(letra_a_presionar)
                letras_a_presionar,numero_letras_a_presionar,texto_letras_a_presionar=recorrer_cadena(numero_letras_a_presionar,letras_a_presionar,texto_letras_a_presionar,TECLAS)
                dibuja_cadena(texto_letras_a_presionar)
                letra_a_presionar=numero_letras_a_presionar[0]
                puntuacion=puntuacion+SUMAR_PUNTUACION*streak
                dibujar_puntuacion(puntuacion)
                racha,streak,limite=calcular_racha_y_streak(racha,streak,limite)
                dibujar_streak(streak)
                dibujar_racha(racha)
            else:
                xvidas=borrar_vida(xvidas)
                vidas=vidas-1
                racha=0
                dibujar_racha(racha)
                if(puntuacion>=RESTAR_PUNTUACION*streak):
                    puntuacion=puntuacion-(RESTAR_PUNTUACION*streak)
                    dibujar_puntuacion(puntuacion)
                else:
                    puntuacion=0
                    dibujar_puntuacion(puntuacion)
                streak=1           
                dibujar_streak(streak)
            
        if tecla_presionada[K_s]:
            id_tecla_presionada=11
            borrar_velocidad=borrar_velocidad+velocidad
            if (id_tecla_presionada==letra_a_presionar):
                despintar_tecla(letra_a_presionar)
                letras_a_presionar,numero_letras_a_presionar,texto_letras_a_presionar=recorrer_cadena(numero_letras_a_presionar,letras_a_presionar,texto_letras_a_presionar,TECLAS)
                dibuja_cadena(texto_letras_a_presionar)
                letra_a_presionar=numero_letras_a_presionar[0]
                puntuacion=puntuacion+SUMAR_PUNTUACION*streak
                dibujar_puntuacion(puntuacion)
                racha,streak,limite=calcular_racha_y_streak(racha,streak,limite)
                dibujar_streak(streak)
                dibujar_racha(racha)
            else:
                xvidas=borrar_vida(xvidas)
                vidas=vidas-1
                racha=0
                dibujar_racha(racha)
                if(puntuacion>=RESTAR_PUNTUACION*streak):
                    puntuacion=puntuacion-(RESTAR_PUNTUACION*streak)
                    dibujar_puntuacion(puntuacion)
                else:
                    puntuacion=0
                    dibujar_puntuacion(puntuacion)
                streak=1           
                dibujar_streak(streak)

        if tecla_presionada[K_t]:
            id_tecla_presionada=4
            borrar_velocidad=borrar_velocidad+velocidad
            if (id_tecla_presionada==letra_a_presionar):
                despintar_tecla(letra_a_presionar)
                letras_a_presionar,numero_letras_a_presionar,texto_letras_a_presionar=recorrer_cadena(numero_letras_a_presionar,letras_a_presionar,texto_letras_a_presionar,TECLAS)
                dibuja_cadena(texto_letras_a_presionar)
                letra_a_presionar=numero_letras_a_presionar[0]
                puntuacion=puntuacion+SUMAR_PUNTUACION*streak
                dibujar_puntuacion(puntuacion)
                racha,streak,limite=calcular_racha_y_streak(racha,streak,limite)
                dibujar_streak(streak)
                dibujar_racha(racha)
            else:
                xvidas=borrar_vida(xvidas)
                vidas=vidas-1
                racha=0
                dibujar_racha(racha)
                if(puntuacion>=RESTAR_PUNTUACION*streak):
                    puntuacion=puntuacion-(RESTAR_PUNTUACION*streak)
                    dibujar_puntuacion(puntuacion)
                else:
                    puntuacion=0
                    dibujar_puntuacion(puntuacion)
                streak=1           
                dibujar_streak(streak)
            
        if tecla_presionada[K_u]:
            id_tecla_presionada=6
            borrar_velocidad=borrar_velocidad+velocidad
            if (id_tecla_presionada==letra_a_presionar):
                despintar_tecla(letra_a_presionar)
                letras_a_presionar,numero_letras_a_presionar,texto_letras_a_presionar=recorrer_cadena(numero_letras_a_presionar,letras_a_presionar,texto_letras_a_presionar,TECLAS)
                dibuja_cadena(texto_letras_a_presionar)
                letra_a_presionar=numero_letras_a_presionar[0]
                puntuacion=puntuacion+SUMAR_PUNTUACION*streak
                dibujar_puntuacion(puntuacion)
                racha,streak,limite=calcular_racha_y_streak(racha,streak,limite)
                dibujar_streak(streak)
                dibujar_racha(racha)
            else:
                xvidas=borrar_vida(xvidas)
                vidas=vidas-1
                racha=0
                dibujar_racha(racha)
                if(puntuacion>=RESTAR_PUNTUACION*streak):
                    puntuacion=puntuacion-(RESTAR_PUNTUACION*streak)
                    dibujar_puntuacion(puntuacion)
                else:
                    puntuacion=0
                    dibujar_puntuacion(puntuacion)
                streak=1           
                dibujar_streak(streak)
            
        if tecla_presionada[K_v]:
            id_tecla_presionada=22
            borrar_velocidad=borrar_velocidad+velocidad
            if (id_tecla_presionada==letra_a_presionar):
                despintar_tecla(letra_a_presionar)
                letras_a_presionar,numero_letras_a_presionar,texto_letras_a_presionar=recorrer_cadena(numero_letras_a_presionar,letras_a_presionar,texto_letras_a_presionar,TECLAS)
                dibuja_cadena(texto_letras_a_presionar)
                letra_a_presionar=numero_letras_a_presionar[0]
                puntuacion=puntuacion+SUMAR_PUNTUACION*streak
                dibujar_puntuacion(puntuacion)
                racha,streak,limite=calcular_racha_y_streak(racha,streak,limite)
                dibujar_streak(streak)
                dibujar_racha(racha)
            else:
                xvidas=borrar_vida(xvidas)
                vidas=vidas-1
                racha=0
                dibujar_racha(racha)
                if(puntuacion>=RESTAR_PUNTUACION*streak):
                    puntuacion=puntuacion-(RESTAR_PUNTUACION*streak)
                    dibujar_puntuacion(puntuacion)
                else:
                    puntuacion=0
                    dibujar_puntuacion(puntuacion)
                streak=1           
                dibujar_streak(streak)
            
        if tecla_presionada[K_w]:
            id_tecla_presionada=1
            borrar_velocidad=borrar_velocidad+velocidad
            if (id_tecla_presionada==letra_a_presionar):
                despintar_tecla(letra_a_presionar)
                letras_a_presionar,numero_letras_a_presionar,texto_letras_a_presionar=recorrer_cadena(numero_letras_a_presionar,letras_a_presionar,texto_letras_a_presionar,TECLAS)
                dibuja_cadena(texto_letras_a_presionar)
                letra_a_presionar=numero_letras_a_presionar[0]
                puntuacion=puntuacion+SUMAR_PUNTUACION*streak
                dibujar_puntuacion(puntuacion)
                racha,streak,limite=calcular_racha_y_streak(racha,streak,limite)
                dibujar_streak(streak)
                dibujar_racha(racha)
            else:
                xvidas=borrar_vida(xvidas)
                vidas=vidas-1
                racha=0
                dibujar_racha(racha)
                if(puntuacion>=RESTAR_PUNTUACION*streak):
                    puntuacion=puntuacion-(RESTAR_PUNTUACION*streak)
                    dibujar_puntuacion(puntuacion)
                else:
                    puntuacion=0
                    dibujar_puntuacion(puntuacion)
                streak=1           
                dibujar_streak(streak)
            
        if tecla_presionada[K_x]:
            id_tecla_presionada=20
            borrar_velocidad=borrar_velocidad+velocidad
            if (id_tecla_presionada==letra_a_presionar):
                despintar_tecla(letra_a_presionar)
                letras_a_presionar,numero_letras_a_presionar,texto_letras_a_presionar=recorrer_cadena(numero_letras_a_presionar,letras_a_presionar,texto_letras_a_presionar,TECLAS)
                dibuja_cadena(texto_letras_a_presionar)
                letra_a_presionar=numero_letras_a_presionar[0]
                puntuacion=puntuacion+SUMAR_PUNTUACION*streak
                dibujar_puntuacion(puntuacion)
                racha,streak,limite=calcular_racha_y_streak(racha,streak,limite)
                dibujar_streak(streak)
                dibujar_racha(racha)
            else:
                xvidas=borrar_vida(xvidas)
                vidas=vidas-1
                racha=0
                dibujar_racha(racha)
                if(puntuacion>=RESTAR_PUNTUACION*streak):
                    puntuacion=puntuacion-(RESTAR_PUNTUACION*streak)
                    dibujar_puntuacion(puntuacion)
                else:
                    puntuacion=0
                    dibujar_puntuacion(puntuacion)
                streak=1           
                dibujar_streak(streak)
            
        if tecla_presionada[K_y]:
            id_tecla_presionada=5
            borrar_velocidad=borrar_velocidad+velocidad
            if (id_tecla_presionada==letra_a_presionar):
                despintar_tecla(letra_a_presionar)
                letras_a_presionar,numero_letras_a_presionar,texto_letras_a_presionar=recorrer_cadena(numero_letras_a_presionar,letras_a_presionar,texto_letras_a_presionar,TECLAS)
                dibuja_cadena(texto_letras_a_presionar)
                letra_a_presionar=numero_letras_a_presionar[0]
                puntuacion=puntuacion+SUMAR_PUNTUACION*streak
                dibujar_puntuacion(puntuacion)
                racha,streak,limite=calcular_racha_y_streak(racha,streak,limite)
                dibujar_streak(streak)
                dibujar_racha(racha)
            else:
                xvidas=borrar_vida(xvidas)
                vidas=vidas-1
                racha=0
                dibujar_racha(racha)
                if(puntuacion>=RESTAR_PUNTUACION*streak):
                    puntuacion=puntuacion-(RESTAR_PUNTUACION*streak)
                    dibujar_puntuacion(puntuacion)
                else:
                    puntuacion=0
                    dibujar_puntuacion(puntuacion)
                streak=1           
                dibujar_streak(streak)
            
        if tecla_presionada[K_z]:
            id_tecla_presionada=19
            borrar_velocidad=borrar_velocidad+velocidad
            if (id_tecla_presionada==letra_a_presionar):
                despintar_tecla(letra_a_presionar)
                letras_a_presionar,numero_letras_a_presionar,texto_letras_a_presionar=recorrer_cadena(numero_letras_a_presionar,letras_a_presionar,texto_letras_a_presionar,TECLAS)
                dibuja_cadena(texto_letras_a_presionar)
                letra_a_presionar=numero_letras_a_presionar[0]
                puntuacion=puntuacion+SUMAR_PUNTUACION*streak
                dibujar_puntuacion(puntuacion)
                racha,streak,limite=calcular_racha_y_streak(racha,streak,limite)
                dibujar_streak(streak)
                dibujar_racha(racha)
            else:
                xvidas=borrar_vida(xvidas)
                vidas=vidas-1
                racha=0
                dibujar_racha(racha)
                if(puntuacion>=RESTAR_PUNTUACION*streak):
                    puntuacion=puntuacion-(RESTAR_PUNTUACION*streak)
                    dibujar_puntuacion(puntuacion)
                else:
                    puntuacion=0
                    dibujar_puntuacion(puntuacion)
                streak=1           
                dibujar_streak(streak)
       
            
    pygame.display.update()#esto actualiza la pantalla
            
#Referencias:
"""Python Mania(2010). "Tutorial Pygame 2: creando una ventana, cargar imagenes y moverlas" [on line].
Recuperado de:https://www.pythonmania.net/es/2010/03/25/tutorial-pygame-2-ventana-e-imagenes/"""
"""Pygame Documentation(s.f.). "pygame" [on line].
Recuperado de:https://www.pygame.org/docs/ref/pygame.html"""
"""McGugan,W. (2007). "Beggining Game Development with Python and Pygame" Capítulos: Chapter 5 Making Things Move;
Chapter 6 Accepting User Input. (91-139p.p), Lugar: United States of America, Editorial:apress"""