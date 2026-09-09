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
    return _totalAmount;
}
int	Account::getNbDeposits( void )
{
    return _totalNbDeposits;
}
int	Account::getNbWithdrawals( void )
{
    return _totalNbWithdrawals;
}
void	Account::displayAccountsInfos( void )
{
    //fonk.un logdaki örnek çıktısı: [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
    //logdaki hangi çıktının hangi fonksiyon tarafından basıldığına karar verirken iki display fonk.u arasında karşılaştırma yaptim
    // loglarda 3 kez basilan ve test.cpp'de de 3 kez çağırılan fonk. bu olduğu için displayAccountInfos'un bu çıktıyı bastığına karar verdim.
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";total:" << _totalAmount << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;

    // _totalNbDeposits, _totalNbWithdrawals, _totalAmount, : tüm accountların toplam değerleri
    //genel tüm hesapların bilgileri basıldığı için yukarıdaki değişkenleri kullandık.
}
void	Account::displayStatus( void ) const
{
    // fonk.un logdaki örenk çıktısı: [19920104_091532] index:4;amount:1234;deposits:0;withdrawals:0
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;


    // _nbDeposits, _nbWithdrawals, _amount : her hesabın diğerlerinden bağımsız kendi değerleri

    //displayStatus'un amacı her hesabın durumunu basmak olduğu için burada bağımsız her hesap için ayrı tutulan değişkneleri kullanıyoruz. 

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
static void	_displayTimestamp( void )
{

}