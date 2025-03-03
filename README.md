# Temporizador One Shot - Raspberry Pi Pico W

Este projeto implementa um **temporizador de um disparo (One Shot)** utilizando o **Raspberry Pi Pico W** e a função `add_alarm_in_ms()` do **Pico SDK**. A simulação pode ser executada na ferramenta **Wokwi**.

## 📌 Requisitos

- **Placa**: Raspberry Pi Pico W
- **Linguagem**: C
- **Ambiente de Desenvolvimento**: VS Code com a extensão **Raspberry Pi Pico SDK** e **Wokwi**
- **Componentes**:
  - 1 Botão (Pushbutton)
  - 3 LEDs (Azul, Vermelho e Verde)
  - 3 Resistores de **330Ω**
  - Raspberry Pi Pico W

## 📜 Estrutura do Código

- **`temporizador_one_shot.c`**: Implementação do código principal com o temporizador de um disparo.
- **`CMakeLists.txt`**: Configuração para compilar o código com o Pico SDK.
- **`diagram.json`**: Diagrama da simulação para Wokwi.

## 🖥️ Como Executar o Projeto

1. **Clone o repositório**.
2. **Abra o código no VS Code**.
3. **Certifique-se de que a extensão Raspberry Pi Pico SDK está instalada**.
4. **Compile o código utilizando a opção de compilação da extensão do Raspberry Pi Pico**.
5. **Simulação no Wokwi**:
   - Abra o arquivo `diagram.json` no Wokwi.
   - Execute a simulação para testar o funcionamento do sistema.

## 🚦 Funcionamento do Temporizador

- O usuário pressiona o **botão**.
- Os três LEDs (**Azul, Vermelho e Verde**) são acesos simultaneamente.
- A cada **3 segundos**, um LED é apagado na seguinte ordem:
  - **Azul → Vermelho → Verde**.
- Após apagar o último LED, o sistema aguarda um novo acionamento do botão.

## 🎯 Objetivos Atendidos

✔ Uso da função `add_alarm_in_ms()` para controle de temporização.

✔ Implementação de **debounce** para evitar múltiplas ativações indevidas.

✔ Simulação compatível com Wokwi e execução no Raspberry Pi Pico W.

---

🚀 **Desenvolvido por Gabriel Menezes**