# SEAL - Sistema de Escala Automatizada de Limpeza

O **SEAL** é um sistema híbrido desenvolvido para automatizar a gestão e a geração de escalas de limpeza em repúblicas estudantis, com foco no cenário de Ouro Preto.O projeto visa eliminar a subjetividade e o esforço manual, garantindo uma distribuição de tarefas justa e transparente.



## 🚀 O Produto

O sistema centraliza a inteligência da escala em um motor automatizado, oferecendo uma interface administrativa robusta para o gestor e um canal de comunicação ágil para os moradores.

### Componentes do Ecossistema
* **Interface Administrativa (Desktop):** Aplicação desenvolvida em **Qt** para uso exclusivo do Administrador.
* **Núcleo de Regras (Core Engine):** Motor de regras complexo responsável pelo algoritmo de distribuição e equilíbrio de carga.
* **Interface de Comunicação (Bot Telegram):** Canal para coleta de indisponibilidades e notificação automática das escalas geradas.
* **API de Integração:** Camada que unifica a comunicação entre todos os componentes e a base de dados central.

## ✨ Funcionalidades Principais

### Gestão (Administrador)
* **Cadastro Geral:** Gerenciamento de moradores (nome, ID Telegram, data de entrada) e cômodos da casa.
* **Configuração de Regras:** Definição da frequência semanal (1 ou 2 vezes) e dos dias de faxina.
* **Painel de Auditoria:** Visualização de relatórios, histórico de escalas passadas e saldo acumulado de folgas.

### Operação (Moradores)
* **Registro de Indisponibilidade:** Notificação de datas em que o morador não poderá realizar a limpeza via comando `/indisponivel`.
* **Consulta de Status:** Verificação da tarefa atual atribuída ao morador via Bot.
* **Notificações Passivas:** Recebimento da escala formatada no grupo da república logo após a geração.

## ⚖️ Regras de Negócio (Justiça Algorítmica)

O motor de geração do SEAL baseia-se em dois pilares fundamentais:
1.  **Rotação Cíclica:** Garante que um morador só repita um cômodo após ter passado por todos os outros disponíveis.
2.  **Compensação (Saldo devedor):** O sistema prioriza a escalação de quem possui mais folgas acumuladas, equilibrando a carga de trabalho a longo prazo.
