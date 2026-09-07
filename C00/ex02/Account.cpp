#include "Account.hpp" 
#include <iostream>

Account::Account( int initial_deposit ):
    _accountIndex( Account::_nbAccounts ), 
    _amount( initial_deposit ),
    _nbDeposits(0),
    _nbWithdrawals(0)
{
    //degiskenleri burda güncellemem lazim
    Account::_nbAccounts++; // her constructor da bir hesap oluşturğu için bir tane artırılacak şekilde yaptık.
    //çıktıyı, değişkeni güncelledikten sonra aşağıdaki gibi yazdırıcam.
    _displayTimestamp(); // bbu fonksiyonu öyle yazmam lazim ki [340957306735] gibi bir şey yazsin.
    std::cout <<"index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

int	Account::getNbAccounts( void ) // _nbAccounts, o ana kadar oluşturulmuş olan toplam account nesnesisayısını tutuyor.
{
    // _NbAccounts ststaişc bir üye olduğu için constructor her çalıştığında 1 artacak.
    // yani tüm objeler aynı tek bir nbAccount değişkenini paylaşıyor. Bu değişken sınıfa ait, OBJEYE DEĞİL.
    // her yeni nesne oluştuğunda constructor ile nbAccounts++ olacağı için burada sadece değişkeni döndürüyoruz.  
    return Account::_nbAccounts; 
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