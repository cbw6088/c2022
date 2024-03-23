import { RouterProvider, createBrowserRouter} from "react-router-dom"
import ArticlesWritePage from "./routes/ArticlesWritePage"
import Login from "./routes/Login"
import SignUp from "./routes/Signup"
import AuthProvider from "./security/AuthContext"
import ArticleDetail from "./routes/ArticleDetail"
import AriticlesHome from "./routes/AriticlesHome"
import ArticleCorrection from "./routes/AriticleCorrection"
import ArticleSearchPage from "./routes/ArticleSearchPage.tsx"
import ArticleMain from "./routes/ArticleMain"
//import { createGlobalStyle, ThemeProvider } from 'styled-components';

const router = createBrowserRouter([
  {
    path: "/",
    element: <Login/>,
  },
  // {
  //   path: "/arti",
  //   element: <ArticleMain/>,
  // },
  {
    path: "/articles",
    element: <ArticleMain/>,
  },
  {
    path: "/articles/save",
    element: <ArticlesWritePage/>
  },
  {
    path:"/signup",
    element:<SignUp/>
  },
  {
    path:"/articles/:id",
    element:<ArticleDetail/>
  },
  {
    path:"/articles/:id/change",
    element:<ArticleCorrection/>
  },
  {
    path:"/articles/search",
    element:<ArticleSearchPage/>
  }
])

function App() {

  return (
    <>
    {/* <GlobalStyle /> */}
      <AuthProvider>
        <RouterProvider router = {router}/>
      </AuthProvider>
    </>
  )
}

export default App
