#include "Account.hpp" 
#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <functional>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ):
    _accountIndex( Account::_nbAccounts ), 
    _amount( initial_deposit ),
    _nbDeposits(0),
    _nbWithdrawals(0)
{
    //degiskenleri burda güncellemem lazim
    _nbAccounts++; // her constructor da bir hesap oluşturğu için bir tane artırılacak şekilde yaptık.
    _displayTimestamp(); // bbu fonksiyonu öyle yazmam lazim ki [340957306735] gibi bir şey yazsin.
    _totalAmount += initial_deposit; // toplam miktara initial_depositi ekliyoruz

    //çıktıyı, değişkeni güncelledikten sonra aşağıdaki gibi yazdırıcam.
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
    _nbDeposits++; //loglarda deposit değerleri atandığında nb_deposits de 1'e çıkıyor
    _totalNbDeposits++; //sonucta total Deposit sayısı da artıyor
    _totalAmount += deposit; //yine toplam değere depositi de ekledik
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
    _amount += deposit; //loglara bakınca deposit değeri amount'a ekleniyor bknz. line: 16-34
    std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
} 
bool	Account::makeWithdrawal( int withdrawal )
{
    if(_amount < withdrawal)
    {
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
        return false;
    }
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    _totalAmount -= withdrawal;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" << withdrawal;
    _amount-= withdrawal;
    std::cout << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true; 
}
int		Account::checkAmount(   void ) const
{
    //normalde test.cpp'de hic cagrilmayan bi fonksiyon
    //amount private olduğu için başkaları tarafından kontrollü erişilebilmesini sağlamak için bi fonksiyon
    return _amount;
}
void Account::_displayTimestamp( void )
{
    std::cout << "[" << std::time(NULL) << "]" ;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout  << "index:" << _accountIndex << ";amount:" << _amount <<";closed" << std::endl; 
}

/*
int		main( void ) {

	typedef std::vector<Account::t>							  accounts_t;
	typedef std::vector<int>								  ints_t;
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;

	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );
	accounts_t				accounts( amounts, amounts + amounts_size );
	accounts_t::iterator	acc_begin	= accounts.begin();
	accounts_t::iterator	acc_end		= accounts.end();

	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 };
	size_t const		d_size( sizeof(d) / sizeof(int) );
	ints_t				deposits( d, d + d_size );
	ints_t::iterator	dep_begin	= deposits.begin();
	ints_t::iterator	dep_end		= deposits.end();

	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 };
	size_t const		w_size( sizeof(w) / sizeof(int) );
	ints_t				withdrawals( w, w + w_size );
	ints_t::iterator	wit_begin	= withdrawals.begin();
	ints_t::iterator	wit_end		= withdrawals.end();

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, dep_begin );
		  it.first != acc_end && it.second != dep_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeDeposit( *(it.second) );
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, wit_begin );
		  it.first != acc_end && it.second != wit_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeWithdrawal( *(it.second) );
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	return 0;
}
*/
