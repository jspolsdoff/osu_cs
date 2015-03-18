#ifndef USER_HPP
#define USER_HPP

class User
{
	private:
	bool key_card;
	bool pass_code;

	public:
	User();
	void setKeyCard();
	bool getKeyCard();
	void setPassCode();
	bool getPassCode();
};

#endif
