#include "Account.hpp" 
#include <iostream>

Account::Account( int initial_deposit ):
    _accountIndex( Account::_nbAccounts ), 
    _amount( initial_deposit ),
    _nbDeposits(0),
    _nbWithdrawals(0)
{
    //degiskenleri burda güncellemem lazim
    _displayTimestamp(); // bbu fonksiyonu öyle yazmam lazim ki [340957306735] gibi bir şey yazsin.
    std::cout <<"index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

int	Account::getNbAccounts( void )
{

}
int	Account::getTotalAmount( void )
{

}
int	Account::getNbDeposits( void )
{

}
int	Account::getNbWithdrawals( void )
{

}
void	Account::displayAccountsInfos( void )
{
}
void	Account::makeDeposit( int deposit )
{
}
bool	Account::makeWithdrawal( int withdrawal )
{
}
int		Account::checkAmount(   void ) const
{

}
void	Account::displayStatus( void ) const
{

}
static void	_displayTimestamp( void )
{}