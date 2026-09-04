class Component {
    public:
        Component(GameObject& associated);
        virtual ~Component();

        virtual void Update(float dt) = 0 ; // virtual indica que a função pode ser sobrescrita(override) por uma classe filha 
        virtual void Render() = 0; // o zero é porque toda classe filha tem que implementar 

    protected:
        GameObject& associated;
};