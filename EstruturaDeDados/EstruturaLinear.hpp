#pragma once
#include <exception>
#include <string>
#include <stdio.h>

#define MAXLISTA  10
#define COD_ERRO_ESTRUTURA_CHEIA  -1
#define COD_ERRO_ESTRUTURA_VAZIA  -2

template<class T>
class EstruturaLinear
{
public:
	EstruturaLinear(void)
	{
		InicializaEstrutura();
	}
	~EstruturaLinear(void){}

	void InicializaEstrutura()
	{
		m_topo = -1;
	}

	bool EstruturaCheia()
	{
		return m_topo == MAXLISTA-1;
	}

	bool EstruturaVazia()
	{
		return m_topo == -1;
	}

	int AdicionaDado(T dado)
	{
		if(EstruturaCheia())
			throw std::overflow_error("Estrutura Cheia!");
		m_topo++;
		m_dados[m_topo] = dado;
		return m_topo;
	}

	virtual T RemoveDado()
	{
		if(EstruturaVazia())
			throw std::underflow_error("Estrutura Vazia!");
		m_topo--;
		return m_dados[m_topo+1];
	}

	T ObterTopo()
	{
		if(EstruturaVazia())
			throw std::underflow_error("Estrutura Vazia!");
		return m_dados[m_topo];
	}

	int ObterIndiceTopo()
	{
		return m_topo;
	}

	void CopiarVetor(T (&destino)[MAXLISTA])
	{
		if(EstruturaVazia())
			throw std::underflow_error("Estrutura Vazia!");
		for (int i = 0; i <= m_topo; i++)
		{
			destino[i] = m_dados[i];
		}
	}

	void ImprimirVetor()
	{
		if(EstruturaVazia())
			throw std::underflow_error("Estrutura Vazia!");
		for (int i = 0; i <= m_topo; i++)
		{
			printf("%i %i\n", i, m_dados[i]);
		}
	}

protected:
	T m_dados[MAXLISTA];
	int m_topo;
};