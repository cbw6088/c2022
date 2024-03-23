import { useEffect, useState  } from "react";
import { useNavigate, Link } from 'react-router-dom';
import { getArticlesApi, searchArticleApi } from "../api/Articles";
import styled from "styled-components"
import searchIcon from '../../assets/icon/click.png';
import commentIcon from '../../assets/icon/comment.png'; 

interface Article {
    title: string;
    hashtag: string;
    nickname: string;
    createAt: string;
    id: string;
}

const Container = styled.div`
    width: 100%;
    height: 100%;
`;
const TopVarContainer = styled.div`
    display: flex;
    //justify-content: space-between;
    align-items: center;
    width: 100%;
    height: 8vh;
    //padding: 0 30px;
    border-bottom: 1px solid #d4d3d3;
    /* box-shadow: 0 2px 4px rgba(0,0,0,0.1); */
`;
const InputContainer = styled.div`
    position: relative;
    width: 60%;
    display: flex;
    align-items: center;
    background-color: white;
    border: 1px solid #d4d3d3;
    border-radius: 20px;
    overflow: hidden;
    margin-left: 450px;
`;
const StyledSelect = styled.select`
  padding: 8px;
  border: none;
  background-color: white;
  color: #333;
  font-size: 12px;
  /* margin-right: 10px; */
`;
const QuestionInput = styled.input`
    flex-grow: 1;
    border: none;
    height: 30px;
    padding: 0 10px;
    border-radius: 20px 0 0 20px;
    &:focus {
        outline: none;
    }
`;
const QuestionButton = styled.button`
    background-image: url(${searchIcon});
    background-size: cover;
    position: absolute;
    background-repeat: no-repeat;
    background-position: center;
    background-color: transparent;
    border: none;
    width: 20px;
    height: 20px;
    right: 10px;
    cursor: pointer;

    &:focus {
        outline: none;
    }
`;
const LoginButton = styled.button`
    width: 10%;
    height: 40px; 
    margin-left: 400px;
    background-color: transparent;
    border: none;
    cursor: pointer;
    &:hover {
        //background-color: #0056b3;
        color: #4980ff;
    }
`;
const ArticlesContainer = styled.div`
    display: flex;
    flex-direction: column;
    align-items: center;
    padding: 20px 0;
    max-height: 500px;
    overflow-y: scroll;
    width: 50%;
    margin: auto;
`;

const ArticleBox = styled.div`
    width: 80%;
    margin: 10px 0;
    padding: 20px;
    border: 1px solid #d4d3d3;
    border-radius: 10px;
    box-shadow: 0 2px 4px rgba(0,0,0,0.1);
`;
const ArticleInfo = styled.div`
    display: flex;
    justify-content: space-between;
    align-items: center;
    width: 100%;
`;
const CommentInfo = styled.div`
    display: flex;
    align-items: center;
    margin-top: 10px;
`;
const CommentImage = styled.img`
    width: 2%; 
`;
const CommentCount = styled.span`
    margin-left: 10px;
    margin-right: 5px;
`;
const Title = styled(Link)`
    flex: 3;
`;
const Hashtag = styled.span`
    flex: 1;
    color: #007bff;
`;
const Nickname = styled.span`
    flex: 1;
`;
const Date = styled.span`
    flex: 1;
    color: #6c757d;
`;
const ButtonContainer = styled.div`
    display: flex;
    justify-content: center;
    margin-top: 50px;
`;

const QuestionActionButton = styled.button`
    width: 200px;
    height: 50px;
    font-size: 15px;
    background-color: #0e6be5;
    color: white;
    border: none;
    border-radius: 5px;
    cursor: pointer;

    &:hover {
        background-color: #0056b3;
    }
`;

function ArticleMain(){
    // const articles = [
    //     { id: 1, title: "Article 1", hashtag: "#React", nickname: "User1", createAt: "2023-03-10", commentCount: 5 },
    //     { id: 2, title: "Article 2", hashtag: "#JavaScript", nickname: "User2", createAt: "2023-03-11", commentCount: 3 },
    //     { id: 3, title: "Article 3", hashtag: "#WebDev", nickname: "User3", createAt: "2023-03-12", commentCount: 2 },
    //     { id: 4, title: "Article 4", hashtag: "#React", nickname: "User1", createAt: "2023-03-10", commentCount: 4 },
    //     { id: 5, title: "Article 5", hashtag: "#JavaScript", nickname: "User2", createAt: "2023-03-11", commentCount: 6 },
    //     { id: 6, title: "Article 6", hashtag: "#WebDev", nickname: "User3", createAt: "2023-03-12", commentCount: 1 },
    // ];    
    const [articles, setArticles] = useState<Article[]>([])
    const navigate = useNavigate(); 


    useEffect(() => {
        const fetchData = async () => {
            try {
                const response = await getArticlesApi();
                setArticles(response.data)
            } catch (error) {
                // 에러 처리
            }
        };
    
        fetchData();
    }, []);

    const onClick = () => {
        console.log('글쓰기페이지로 이동')
        navigate('/articles/save');
    };

    const onLogout = () => {
        console.log('로그아웃');
        navigate('/');
    };

    const onSearch = () => {
        const searchArticle = async () => {  
            try{
                const response = await searchArticleApi(selectedValue, keyword)
                if(response.status === 200){
                    console.log(response)
                    if(response.data.length === 0){
                        window.alert('일치하는 게시글이 없습니다.')
                    }
                    else{
                        console.log(response.data)
                        navigate('/articles/search', { state: { data: response.data } })
                    }
                }
            }
            catch(e){
                console.log(e)
            }  
        };
        searchArticle();
    };

    const [selectedValue, setSelectedValue] = useState('');
    const [keyword, setKeyword] = useState('');
    const handleSelectChange = (event: any) => {
        setSelectedValue(event.target.value);
    };
    const handleKeywordChange = (event: any) => {
        setKeyword(event.target.value);
    }

    return(
        <Container>
            <TopVarContainer>
                <InputContainer>
                    <StyledSelect id="pet-select" value={selectedValue} onChange={handleSelectChange}>
                        <option value="">선택</option>
                        <option value="TITLE">제목</option>
                        <option value="CONTENT">내용</option>
                        <option value="ID">아이디</option>
                        <option value="NICKNAME">닉네임</option>
                        <option value="HASHTAG">해시태그</option>
                    </StyledSelect>
                    <QuestionInput placeholder="검색..." onChange={handleKeywordChange}/>
                    <QuestionButton onClick={onSearch}/>
                </InputContainer>
                <LoginButton onClick={onLogout}>로그아웃</LoginButton>
            </TopVarContainer>
            <ArticlesContainer>
            {articles.map((article, index) => (
                <ArticleBox key={index}>
                    <ArticleInfo>
                        <Title to={`/articles/${article.id}`}>{article.title}</Title>
                        <Hashtag>{article.hashtag}</Hashtag>
                        <Nickname>{article.nickname}</Nickname>
                        <Date>{article.createAt}</Date>
                    </ArticleInfo>
                    <CommentInfo>
                        <CommentImage src={commentIcon} />
                        {/* <CommentCount>{article.commentCount}</CommentCount> */}
                        <span>Comments</span>
                    </CommentInfo>
                </ArticleBox>
            ))}
        </ArticlesContainer>

            <ButtonContainer>
                <QuestionActionButton onClick={onClick}>Question</QuestionActionButton>
            </ButtonContainer>
        </Container>
    )
}

export default ArticleMain