# Trabalho com Display-Sete-Segmentos feito na plataforma Zephyr RTOS

### Esta atividade foi feita para a disciplina de Sistema Embarcados como forma de avaliação fazendo parte do 5º periodo do Curso Análise e Desenvolvimento de Sistemas do IFPE campus Garanhuns e foi orientada pelo Professor David Alain do Nascimento

---
>  ### Atividade foi feita pelos integrantes:
  - ##### João Otávio Gurgel Souto
  - ##### Álvaro Alexandre da Silva Neto
---
> ### A placa que foi usada para implementar a logica foi a ***STM32F303RE NUCLEO-F303RE***
![imagem da Placa nucleo_f303re que foi usada](https://estore.st.com/media/catalog/product/p/f/pf260945_m_3.jpg?quality=80&bg-color=255,255,255&fit=bounds&height=700&width=700&canvas=700:700)

> [!NOTE]
> ##### ***SOBRE A PLACA***
> A placa STM32 Nucleo oferece uma maneira acessível e flexível para os usuários experimentarem novas ideias e construirem protótipos com qualquer linha de microcontroladores STM32, escolhendo entre várias combinações de desempenho, consumo de energia e recursos

> [!NOTE]
> ##### ***SOBRE A PLACA***
> É ideal para desenvolvimento em aplicações que exigem desempenho e precisão, como pinos, controladroes,sensores e aplicações de processamento de sinais. Ela é compativel com plataformas de desenvolvimento de Sistemas Arduinos como a Zephyr, que facilita o desenvolvimento e a programação!

> [!TIP]
> ##### Para mais informações sobre a placa e seu conteúdo, visite o site Oficial [Site oficial da ARM MBED](https://os.mbed.com/platforms/ST-Nucleo-F303RE/)
---
> ## Funcionamento do sistema
#### A atividade utiliza uma placa Nucleo-F303RE para controlar um display de 7 segmentos montado em uma protoboard; através da lógica feita pela gente na `LINGUAGEM C` vai permitir que ao pressionar um botão na placa, o display mostra os números de 1 a 9 seguidos pelas letras de A a F em sequência, repetindo o ciclo até a próxima interação

> [!NOTE]
> O display de 7 segmentos é um visor digital básico, composto por sete LEDs que se acendem em diferentes combinações para formar números de 0 a 9 e tambem permite até memso forma algumas letras. Por sua simplicidade e baixo custo, é bem utilizado em varias coisas do nosso dia-a-dia como em relógios digitais, calculadoras, visores ou telinhas que estão presentes em dispositivos, contadores, paineis de controle entre outros dispositivos eletrônicos

> ### Um display de 7 segmentos
> ![imagem de um display de 7 segmentos](https://cdn.awsli.com.br/600x700/468/468162/produto/29852647/25bb7e4a7b.jpg)

> ### Parte logica do display
> ![Imagem da parte logica do display](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQzy__YEudyts_y8R45JdIMumyO_sFbso2qZw&s)
---
> ### Abaixo pode ser visto um vidio de demostração do projeto funcionando:
> ### [https://youtu.be/bGqOEyln_w0](https://youtu.be/bGqOEyln_w0)
    
  
