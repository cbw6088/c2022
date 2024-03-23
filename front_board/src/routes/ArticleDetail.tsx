import { useEffect, useState } from 'react';
import { useParams, useNavigate } from 'react-router-dom';
import styled from 'styled-components';
import { deleteArticleApi, getArticleApi } from '../api/Articles'; // 게시글 상세 정보를 가져오는 API 함수
import { useAuth } from '../security/AuthContext';
import CommentComponent from '../components/Comment';
import searchIcon from '../../assets/icon/click.png';

interface Article {
    title: string;
    hashtag: string;
    nickname: string;
    createAt: string;
    content: string;
}
const Wrapper = styled.div`
    width: 100%;
    height: 100%;
`;
const TopVarContainer = styled.div`
    display: flex;
    align-items: center;
    width: 100%;
    height: 8vh;
    border-bottom: 1px solid #d4d3d3;
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
const CenteredContainer = styled.div`
    display: flex;
    justify-content: center;
    align-items: center;
    flex-direction: column; 
    margin-top: 20px;
    border-collapse: collapse;
`;
const ArticleTable = styled.table`
    width: 60%;
    box-shadow: 1px 2px 2px 3px rgba(0,0,0,0.1);
`;
const InfoTable = styled.td`
    padding: 10px;
    border-bottom: 1px solid #ddd;
    display: flex;
    justify-content: space-between;
    align-items: center;
`;
const ContentTable = styled.td`
    //border-bottom: 1px solid #ddd;
    display: block;
    width: 100%;
    height: 20rem;
    padding: 10px;
`;
const HashtagTable = styled.td`
    border-top: 1px solid #ddd;
    padding: 10px;
    display: block; 
`;
const ButtonContainer = styled.div`
    display: flex;
    justify-content: space-between;
    margin-top: 0.5rem;
    width: 60%;
    //background-color: black;
`;
const EditDeleteContainer = styled.div`
    display: flex;
    gap: 10px;
`;
const Button = styled.button`
    padding: 10px 20px;
    border: 1.5px solid #007bff;
    border-radius: 5px;
    /* background-color: #007bff; */
    background-color: transparent;
    color: #007bff;
    font-size: 16px;
    cursor: pointer;
    margin: 0.1rem;
    transition: background-color 0.3s;
    &:hover {
        border: 1.5px solid #0056b3;
        background-color: #0056b3;
        color: white;
    }
`;

function ArticleDetail() {
    const { id } = useParams(); // URL에서 게시글 ID 추출
    const [article, setArticle] = useState<Article>();
    const navigate = useNavigate(); 
    const auth = useAuth();
    
    useEffect(() => {
        const fetchArticle = async () => {
            try {
                const response = await getArticleApi(id); // API 호출
                // console.log(response);
                setArticle(response.data);
            } catch (error) {
                // 에러 처리
            }
        };

        fetchArticle();
    }, [id]);

    if (!article) {
        return <div>Loading...</div>;
    }

    const onBackButton = () => {
        console.log('뒤로 이동');
        navigate('/articles');
    };

    const onDeleteButton = () => {
        console.log('삭제 요청 완료');
        const handleSubmit = async () => {
            try {
                const response = await deleteArticleApi(id);
        
                if (response.status === 200) {
                    window.alert('삭제 완료!!');
                    navigate('/articles');
                    console.log('삭제 완료');
                } else {
                    console.log('삭제 실패');
                }
            } catch (error) {
                console.log('에러 발생:', error);
            }
        }
        handleSubmit()
    };

    const onCorrectionButton = () => {
        console.log('수정 시작');
        // navigate('/articles/change', { state: { id: id } });
        navigate(`/articles/${id}/change`)
    };
    return (
        <Wrapper>
            <TopVarContainer>
                <InputContainer>
                    <StyledSelect id="pet-select">
                        <option value="">선택</option>
                        <option value="TITLE">제목</option>
                        <option value="CONTENT">내용</option>
                        <option value="ID">아이디</option>
                        <option value="NICKNAME">닉네임</option>
                        <option value="HASHTAG">해시태그</option>
                    </StyledSelect>
                    <QuestionInput placeholder="검색..." />
                    <QuestionButton/>
                </InputContainer>
                <LoginButton>로그아웃</LoginButton>
            </TopVarContainer>
            <CenteredContainer>
                <ArticleTable>
                    <InfoTable>
                    <span style={{flexGrow: 1}}>{article.title}</span>
                    <div style={{display: 'flex', gap: '10px'}}>
                        <span>{article.nickname}</span>
                        <span>{article.createAt.split('T')[0]}</span>
                    </div>
                    </InfoTable> 
                    <ContentTable>{article.content}</ContentTable>                  
                    <HashtagTable>{article.hashtag}</HashtagTable>    
                </ArticleTable>                   
                {auth.username === article.nickname ? (
                    <ButtonContainer>
                        <Button onClick={onBackButton}>Back</Button>
                        <EditDeleteContainer>
                            <Button onClick={onCorrectionButton}>Correction</Button>
                            <Button onClick={onDeleteButton}>Delete</Button>
                        </EditDeleteContainer>
                    </ButtonContainer>
                        ):(
                        <ButtonContainer>
                                <Button onClick={onBackButton}>Back</Button>
                        </ButtonContainer>
                )}
                <CommentComponent/>
            </CenteredContainer>
        </Wrapper>
    );
}

export default ArticleDetail;
