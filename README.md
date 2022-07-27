# 42 Labs 3º Edição

Este é desafio técnico do processo seletivo da 3º Edição do 42 Labs. É neste momento que você poderá aplicar os seus conhecimentos, trabalhando com outros Cadetes para desenvolver uma aplicação que tem como o objetivo apresentar conhecimentos que passam pelas área de desenvolvimento web e redes, que serão especialmente importantes no 42 Labs.

## Desafio

Em uma linha: Aplicação de monitoramento de serviços web.

Vamos monitorar serviços web utilizando 3 protocolos: *HTTP*, *PING* e *DNS*. Para cada protocolo, existirão configurações que definem como o monitoramento vai acontecer, assim como o endereço do serviço monitorado. As configurações de monitoramento estarão em um arquivo com nome `monitoring.db`, onde cada linha representa uma espécie de monitoramento com base nas configurações definidas na mesma linha. O programa `monitoring` irá procurar e analisar esse arquivo, iniciando o processo de monitoramento.

Velho conhecido seu, o *C* será utilizado para o desenvolvimento.

### monitoring.db

O arquivo `monitoring.db` define como a sua aplicação vai agir. Esse arquivo tem uma estrutura estrita e deve ser rejeitado caso não corresponda a essa estrutura.

A estrutura é definida por linhas e colunas, onde cada linha terá as configurações separadas por um TAB, que definem as colunas. Para cada monitoramento, as configurações até a 3º coluna serão as mesmas, já a partir da 4º a configuração é específica, baseando-se no protocolo escolhido na 2º coluna.

As configurações para cada protocolo são:

| Protocolo   | Configurações                                                           |
|-------------|-------------------------------------------------------------------------|
| HTTP        | nome, protocolo, endereço, método HTTP, código HTTP esperado, intervalo |
| PING        | nome, protocolo, endereço, intervalo                                    |
| DNS         | nome, protocolo, endereço, intervalo, servidor DNS                      |

Abaixo, exemplo do arquivo descrito acima:

```txt
# monitoring.db

intra	HTTP	intra.42.fr	GET	200	120
game ping test	PING	game.42sp.org.br	60
workspaces monitoring	PING	workspaces.42sp.org.br	60
```

### monitoring

O programa `monitoring` é onde tudo vai acontecer. Lendo o arquivo de configuração, os serviços devem começar a ser monitorados da mesma forma que foram configurados.

Informações dos serviços monitorados devem ser exibidas na saída padrão de uma forma sucinta e informações mais detalhadas para análises aprofundadas devem ser armazenadas no arquivo `monitoring.log` usando uma estrutura estrita e padronizada, definida por você. Deve ser possível também adquirir as informações sucintas, as mesmas que uma vez estavam na saída padrão, apenas utilizando o argumento `--simplify` no programa.

Um serviço saudável é aquele que consegue responder a requisição do monitoramento de forma esperada, em contrapartida ao serviço não saudável que não responde de forma esperada. Sendo um serviço de monitoramento, a sua aplicação deve ser capaz de identificar e exibir essa informação corretamente.

### É necessário

- Que o programa seja útil e realmente funcione como um serviço de monitoramento de serviços.
- Que exista um programa chamado `monitoring`.
- O arquivo `monitoring.db` deve ser analisado e validado pelo programa.
- Os serviços configurados para monitoramento devem seguir as configurações definidas.
- Arquivo `monitoring.log` deve armazenar todas as informações possíveis do monitoramento e deve ser possível traduzir a sua estrutura de uma forma resumida, sucinta utilizando o argumento ao programa `--simplify`.

### O que será avaliado

- Código bem escrito e limpo.
- A documentação do seu código.
- Ferramentas que foram utilizadas e por quê.
- Sua criatividade e capacidade de lidar com problemas diferentes.
- Alinhamento do seu projeto com a proposta.

### O mínimo necessário

- README.md com a documentação contendo informações do projeto.

### Bônus

Os itens a seguir não são obrigatórios, mas são funcionalidades que darão mais valor ao seu programa.

- Notificação de serviço não saudável no Discord, email, Slack ou Webhook.
- Testes.
- Identificação de comportamentos incomuns dos serviços monitorados, como o aumento de latência de resposta.
- Análise agregada dos dados do arquivo `monitoring.log`, exibindo diagramas e gráficos da CLI.
- Parseamento de argumentos UNIX-Like podendo filtrar ou alterar comportamentos da aplicação.
- Cuidados especiais com otimização e padrões de código.
- Possibilidade de monitoramento MQTT e TCP.
- Uso de ferramentas externas para planejamento nas etapas de desenvolvimento.

<sub><sup>[Importante](https://imgs.xkcd.com/comics/networking_problems.png)</sup></sub>
