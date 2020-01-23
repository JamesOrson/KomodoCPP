using Komodo.Core.Engine.Entities;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace Komodo.Core.Engine.Components
{
    public interface IComponent
    {
        #region Members

        #region Public Members
        IEntity Parent { get; }
        #endregion Public Members

        #endregion Members

        #region Member Methods
        
        #region Public Member Methods
        void Draw(SpriteBatch spriteBatch);
        void Update(GameTime gameTime);
        #endregion Public Member Methods
        
        #endregion Member Methods
    }
}